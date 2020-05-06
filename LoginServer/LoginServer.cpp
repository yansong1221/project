#include "LoginServer.h"
#include <functional>
#include "CMD.h"
#include "Common/Define.h"
#include "DBServer/CMD.h"

LoginServer::LoginServer()
	: eventDispatcher_(this),
	  TCPServer_(this)
{
}

LoginServer::~LoginServer()
{
}

bool LoginServer::OnStartUp()
{
	Logger::getInstance().startLogger("./log/LoginServer/");

	Logger::getInstance().info("连接数据库服务器");

	DBClient_.setConnectHandle(std::bind(&LoginServer::OnDBConnect, this, std::placeholders::_1));
	DBClient_.setReadHandle(std::bind(&LoginServer::OnDBMessage, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
	DBClient_.setCloseHandle(std::bind(&LoginServer::OnDBDisconnect, this));
	DBClient_.connect("127.0.0.1", 8100);

	Logger::getInstance().info("正在监听端口:%d", 10000);
	if (TCPServer_.listen(10000, 1024) == false)
		return false;

	//注册网络消息

	//通过token登录
	messageMgr_.Register(CMD_LOGIN_C_LOGIN_TOKEN, CALL_BACK_2(&LoginServer::OnUserLogin));
	messageMgr_.Register(CMD_LOGIN_C_FRIEND_MESSAGE, CALL_BACK_2(&LoginServer::onUserFriendMessage));
	messageMgr_.Register(CMD_LOGIN_C_GROUP_MESSAGE, CALL_BACK_2(&LoginServer::onUserGroupMessage));

	//注册数据库回复消息
	DBMessageMgr_.Register(CMD_DB_S_LOGIN_RESULT, CALL_BACK_2(&LoginServer::onDBLoginResult));
	DBMessageMgr_.Register(CMD_DB_S_LOAD_FRIEND_LIST_RESULT, CALL_BACK_2(&LoginServer::onDBLoadFriendListResult));
	DBMessageMgr_.Register(CMD_DB_S_LOAD_GROUP_LIST_RESULT, CALL_BACK_2(&LoginServer::onDBLoadGroupList));
	return true;
}

bool LoginServer::OnShutDown()
{
	DBClient_.close();
	Logger::getInstance().stopLogger();
	return true;
}
void LoginServer::onNewConnect(uint32_t socketID)
{
}
void LoginServer::onNewMessage(uint32_t socketID, uint32_t msgID, const void *data, size_t sz)
{
	try
	{
		std::string str((const char *)data, sz);
		auto doc = nlohmann::json::parse(str);

		uint32_t contextID = doc["contextID"];
		nlohmann::json data = doc["data"];

		if (messageMgr_.Invoke(msgID, socketID, doc) == false)
		{
			fprintf(stderr, "未注册的消息->msgID:%d", msgID);
			return;
		}
	}
	catch (const std::exception &)
	{
		return;
	}
}
void LoginServer::onCloseConnect(uint32_t socketID)
{
	auto user = userManager_.searchUserBySocketID(socketID);
	if (user == nullptr)
		return;

	//通知所有好友下线
	auto friendGroup = userFriendGroupManager_.searchUserFriendGroup(user->userInfo().userID);
	if (friendGroup)
	{
		nlohmann::json doc;
		doc["userID"] = user->userInfo().userID;
		doc["status"] = USER_STATUS_OFFLINE;
		for (auto v : friendGroup->allFriend())
		{
			auto friendUser = userManager_.searchUserByUserID(v->userID);
			if (friendUser == nullptr)
				continue;
			TCPServer_.sendData(friendUser->socketID(), CMD_LOGIN_S_USER_STATUS, doc);
		}
	}
	//移除好友列表
	userFriendGroupManager_.removeUserFriendGroup(user->userInfo().userID);
	//删除实例
	userManager_.removeUserByUserID(user->userInfo().userID);
}

void LoginServer::OnDBConnect(bool success)
{
	Logger::getInstance().info("连接数据库服务器:%s", (success ? "成功" : "失败"));

	//加载群组
	if (success)
	{
		groupManager_.clear();
		sendDBMessage(CMD_DB_C_LOAD_GROUP_LIST);
	}
}

void LoginServer::OnDBMessage(uint32_t msgID, const void *data, size_t sz)
{
	try
	{
		std::string str((const char *)data, sz);
		auto doc = nlohmann::json::parse(str);

		uint32_t contextID = doc["contextID"];
		nlohmann::json data = doc["data"];

		if (DBMessageMgr_.Invoke(msgID, contextID, data) == false)
		{
			Logger::getInstance().warning("未注册的数据库回复消息->msgID:%d", msgID);
			return;
		}
	}
	catch (const std::exception &e)
	{
		Logger::getInstance().error("OnDBMessage: %s", e.what());
		return;
	}
}

void LoginServer::OnDBDisconnect()
{
	Logger::getInstance().info("数据库断开连接");
}
void LoginServer::sendDBMessage(uint32_t msgID, uint32_t contextID, const nlohmann::json &msg)
{
	nlohmann::json doc;
	doc["contextID"] = contextID;
	doc["data"] = msg;

	DBClient_.sendData(msgID, doc);
}

int LoginServer::run()
{
	return eventDispatcher_.run();
}

void LoginServer::OnUserLogin(uint32_t socketID, const nlohmann::json &msg)
{
	auto user = userManager_.searchUserBySocketID(socketID);
	if (user != nullptr)
	{
		nlohmann::json doc;
		doc["code"] = 101;
		doc["message"] = "您已经登录过了，不要重复登录！";
		TCPServer_.sendData(socketID, CMD_LOGIN_S_LOGIN_FAILD, doc);
		return;
	}

	sendDBMessage(CMD_DB_C_LOGIN_TOKEN, socketID, msg);
}
//用户好友消息
void LoginServer::onUserFriendMessage(uint32_t socketID, const nlohmann::json &msg)
{
	auto user = userManager_.searchUserBySocketID(socketID);
	if (user == nullptr)
		return;

	int toUserID = msg["toUserID"];
	std::string content = msg["content"];
	time_t currentTime = time(nullptr);
	long long messageIndex = userFriendGroupManager_.updateMessageIndex(user->userInfo().userID,toUserID);
	
	//在线发送
	auto friendUser = userManager_.searchUserByUserID(toUserID);
	if (friendUser)
	{
		nlohmann::json doc;
		doc["fromUserID"] = user->userInfo().userID;
		doc["toUserID"] = toUserID;
		doc["content"] = content;
		doc["currentTime"] = currentTime;
		doc["messageIndex"] = messageIndex;

		TCPServer_.sendData(friendUser->socketID(), CMD_LOGIN_S_FRIEND_MESSAGE, doc);
		TCPServer_.sendData(user->socketID(), CMD_LOGIN_S_FRIEND_MESSAGE, doc);
	}

	

	//保存数据库
	nlohmann::json doc;
	doc["userID"] = user->userInfo().userID;
	doc["toUserID"] = toUserID;
	doc["content"] = content;
	doc["isRead"] = friendUser ? 1 : 0;
	doc["currentTime"] = currentTime;
	doc["messageIndex"] = messageIndex;

	sendDBMessage(CMD_DB_C_SAVE_FRIEND_MESSAGE, socketID, doc);
}
//用户群消息
void LoginServer::onUserGroupMessage(uint32_t socketID, const nlohmann::json &msg)
{
	Logger::getInstance().info(msg.dump().c_str());
	auto user = userManager_.searchUserBySocketID(socketID);
	if (user == nullptr)
		return;

	uint64_t groupID = msg["groupID"];
	std::string content = msg["content"];
	time_t curTime = time(nullptr);

	auto group = groupManager_.searchGroup(groupID);
	if (group == nullptr)
		return;

	long long messageIndex = group->updateMessageIndex();

	nlohmann::json doc;
	doc["fromUserID"] = user->userInfo().userID;
	doc["content"] = content;
	doc["currentTime"] = curTime;
	doc["groupID"] = groupID;
	doc["messageIndex"] = messageIndex;

	for (auto member : group->allMember())
	{
		auto user = userManager_.searchUserByUserID(member->userID);
		if (user == nullptr)
			continue;
		TCPServer_.sendData(user->socketID(),CMD_LOGIN_S_GROUP_MESSAGE,doc);
	}

	sendDBMessage(CMD_DB_C_SAVE_GROUP_MESSAGE,0,doc);
}

//登录结果
void LoginServer::onDBLoginResult(uint32_t contextID, const nlohmann::json &msg)
{
	Logger::getInstance().info(msg.dump().c_str());

	//重复登录 不处理
	auto user = userManager_.searchUserBySocketID(contextID);
	if (user != nullptr)
		return;

	int code = msg["code"];
	std::string message = msg["message"];

	//登录失败
	if (code != 0)
	{
		TCPServer_.sendData(contextID, CMD_LOGIN_S_LOGIN_FAILD, msg);
		return;
	}

	//用户信息
	UserInfo userInfo;
	userInfo.userID = msg["userID"];
	userInfo.sex = msg["sex"];
	userInfo.nickName = msg["nickName"];
	userInfo.headUrl = msg["headUrl"];

	//顶号
	user = userManager_.searchUserByUserID(userInfo.userID);
	if(user != nullptr)
	{
		TCPServer_.sendData(user->socketID(),CMD_LOGIN_S_LOGIN_AFRESH,nlohmann::json());
		user->socketID(contextID);
		userFriendGroupManager_.removeUserFriendGroup(user->userInfo().userID);
	}
	else
	{
		//创建登录成功实例
		user = userManager_.createUser(contextID, userInfo);
	}
	
	TCPServer_.sendData(contextID, CMD_LOGIN_S_LOGIN_SUCCESS, msg);

	//加载好友列表
	nlohmann::json doc;
	doc["userID"] = user->userInfo().userID;
	sendDBMessage(CMD_DB_C_LOAD_FRIEND_LIST, contextID, doc);
}
//加载好友列表结果
void LoginServer::onDBLoadFriendListResult(uint32_t contextID, const nlohmann::json &msg)
{
	Logger::getInstance().info(msg.dump().c_str());

	auto user = userManager_.searchUserBySocketID(contextID);
	if (user == nullptr)
		return;

	int code = msg["code"];
	if (code != 0)
	{
		return;
	}

	//保存好友列表
	auto friendGroup = userFriendGroupManager_.createUserFriendGroup(user->userInfo().userID);
	for (int i = 0; i < msg["data"].size(); ++i)
	{
		nlohmann::json item = msg["data"][i];

		ServerFriendInfo FriendInfo;
		FriendInfo.userID = item["userID"];
		FriendInfo.sex = item["sex"];
		FriendInfo.nickName = item["nickName"];
		FriendInfo.headUrl = item["headUrl"];
		FriendInfo.alias = item["alias"];
		FriendInfo.messageIndex = item["messageIndex"];

		friendGroup->appendFriendInfo(FriendInfo);
	}

	//通知给在线的好友
	nlohmann::json doc;
	doc["userID"] = user->userInfo().userID;
	doc["status"] = user->userStatus();
	for (auto v : friendGroup->allFriend())
	{
		auto friendUser = userManager_.searchUserByUserID(v->userID);
		if (friendUser == nullptr)
			continue;
		TCPServer_.sendData(friendUser->socketID(), CMD_LOGIN_S_USER_STATUS, doc);
	}

	//通知好友列表
	doc = nlohmann::json::array();
	for (auto v : friendGroup->allFriend())
	{
		nlohmann::json item;
		item["userID"] = v->userID;
		item["sex"] = v->sex;
		item["nickName"] = v->nickName;
		item["headUrl"] = v->headUrl;
		item["alias"] = v->alias;

		auto friendUser = userManager_.searchUserByUserID(v->userID);
		item["status"] = friendUser ? friendUser->userStatus() : USER_STATUS_OFFLINE;

		doc.push_back(item);
	}
	TCPServer_.sendData(user->socketID(), CMD_LOGIN_S_FRIEND_LIST, doc);
}
//加载群列表
void LoginServer::onDBLoadGroupList(uint32_t contextID, const nlohmann::json &msg)
{
	uint64_t groupID = msg["groupID"];
	std::string groupName = msg["groupName"];
	long long messageIndex = msg["messageIndex"];

	auto group = groupManager_.createGroup(groupID, groupName,messageIndex);
	for (int i = 0; i < msg["members"].size(); ++i)
	{
		GroupMemberInfo info;
		info.userID = msg["members"][i]["userID"];
		info.level = msg["members"][i]["level"];
		info.groupNickName = msg["members"][i]["groupNickName"];
		group->appendMember(info);
	}
}