
#include "LoginServer.h"
#include "CMD.h"
#include "Common/Define.h"
#include "DBServer/CMD.h"
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
//加载好友聊天消息
void LoginServer::onUserLoadFriendMessage(uint32_t socketID, const nlohmann::json &msg)
{
	try
	{
		auto user = userManager_.searchUserBySocketID(socketID);
		if (user == nullptr)
			return;

		int toUserID = msg["toUserID"];
		int pageNo = msg["pageNo"];
		int limit = msg["limit"];

		if (pageNo < 0 || limit < 0)
			return;

		nlohmann::json doc;
		doc["userID"] = user->userInfo().userID;
		doc["toUserID"] = toUserID;
		doc["pageNo"] = pageNo;
		doc["limit"] = limit;
		sendDBMessage(CMD_DB_C_LOAD_FRIEND_MESSAGE, socketID, doc);
	}
	catch (const std::exception &e)
	{
		Logger::getInstance().error("onUserLoadFriendMessage:%s", e.what());
	}
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
	long long messageIndex = userFriendGroupManager_.updateMessageIndex(user->userInfo().userID, toUserID);

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
	doc["currentTime"] = currentTime;
	doc["messageIndex"] = messageIndex;

	sendDBMessage(CMD_DB_C_SAVE_FRIEND_MESSAGE, socketID, doc);
}
//加载最近会话
void LoginServer::onUserLoadRecentSession(uint32_t socketID, const nlohmann::json &msg)
{

	auto user = userManager_.searchUserBySocketID(socketID);
	if (user == nullptr)
		return;

	int pageNo = msg["pageNo"];
	int limit = msg["limit"];

	nlohmann::json doc;
	doc["userID"] = user->userInfo().userID;
	doc["pageNo"] = pageNo;
	doc["limit"] = limit;

	sendDBMessage(CMD_DB_C_LOAD_RECENT_SESSION, socketID, doc);
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
		TCPServer_.sendData(user->socketID(), CMD_LOGIN_S_GROUP_MESSAGE, doc);
	}

	sendDBMessage(CMD_DB_C_SAVE_GROUP_MESSAGE, 0, doc);
}