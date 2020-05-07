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
	messageMgr_.Register(CMD_LOGIN_C_LOAD_FRIEND_MESSAGE, CALL_BACK_2(&LoginServer::onUserLoadFriendMessage));
	messageMgr_.Register(CMD_LOGIN_C_LOAD_RECENT_SESSION, CALL_BACK_2(&LoginServer::onUserLoadRecentSession));

	//注册数据库回复消息
	DBMessageMgr_.Register(CMD_DB_S_LOGIN_RESULT, CALL_BACK_2(&LoginServer::onDBLoginResult));
	DBMessageMgr_.Register(CMD_DB_S_LOAD_FRIEND_LIST_RESULT, CALL_BACK_2(&LoginServer::onDBLoadFriendListResult));
	DBMessageMgr_.Register(CMD_DB_S_LOAD_GROUP_LIST_RESULT, CALL_BACK_2(&LoginServer::onDBLoadGroupList));
	DBMessageMgr_.Register(CMD_DB_S_LOAD_FRIEND_MESSAGE_RESULT, CALL_BACK_2(&LoginServer::onDBLoadFriendMessageResult));
	DBMessageMgr_.Register(CMD_DB_S_LOAD_RECENT_SESSION_RESULT,CALL_BACK_2(&LoginServer::onDBLoadRecentSessionResult));

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

		if (messageMgr_.Invoke(msgID, socketID, doc) == false)
		{
			Logger::getInstance().warning("未注册的消息->msgID:%d", msgID);
			return;
		}
	}
	catch (const std::exception &e)
	{
		Logger::getInstance().warning("用户消息:%d,出现异常:%s,socketID:%d", msgID, e.what(), socketID);
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