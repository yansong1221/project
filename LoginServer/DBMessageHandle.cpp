
#include "LoginServer.h"
#include "DBServer/CMD.h"
#include "CMD.h"
#include "Common/Define.h"
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
	if (user != nullptr)
	{
		TCPServer_.sendData(user->socketID(), CMD_LOGIN_S_LOGIN_AFRESH, nlohmann::json());
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

	auto group = groupManager_.createGroup(groupID, groupName, messageIndex);
	for (int i = 0; i < msg["members"].size(); ++i)
	{
		GroupMemberInfo info;
		info.userID = msg["members"][i]["userID"];
		info.level = msg["members"][i]["level"];
		info.groupNickName = msg["members"][i]["groupNickName"];
		group->appendMember(info);
	}
}
//加载好友历史记录结果
void LoginServer::onDBLoadFriendMessageResult(uint32_t contextID, const nlohmann::json &msg)
{
	TCPServer_.sendData(contextID, CMD_LOGIN_S_LOAD_FRIEND_MESSAGE, msg);
}
void LoginServer::onDBLoadRecentSessionResult(uint32_t contextID,const nlohmann::json& msg)
{
	TCPServer_.sendData(contextID, CMD_LOGIN_S_LOAD_RECENT_SESSION, msg);
}