#include "DBServer.h"
#include "CMD.h"
#include <fmt/core.h>

#define DEFAULT_LISTEN_PORT 8100

struct BaseDBOperator : public IThreadTask
{
	BaseDBOperator(uint32_t socketID, uint32_t contextID, const nlohmann::json &msg, DBServer *server)
		: server_(server),
		  socketID_(socketID),
		  contextID_(contextID),
		  data_(msg)
	{
	}

	void sendData(uint32_t msgID, const nlohmann::json &msg)
	{
		server_->sendData(msgID, socketID_, contextID_, msg);
	}

	uint32_t socketID_;
	uint32_t contextID_;
	DBServer *server_;
	nlohmann::json data_;
};

DBServer::DBServer()
	: eventDispatcher_(this),
	  TCPServer_(this)
{
}

DBServer::~DBServer()
{
}

bool DBServer::OnStartUp()
{
	Logger::getInstance().startLogger("./log/DBServer/");

	Logger::getInstance().info("初始化服务器");
	Logger::getInstance().info("开始监听端口:%d", DEFAULT_LISTEN_PORT);
	if (TCPServer_.listen(DEFAULT_LISTEN_PORT, 1024) == false)
		return false;

	try
	{
		CMYSQLPool::GetInstance()->Initialization("192.168.1.17", 3306, "im", "youxi", "RGrSZfWZNtNRBbww");
	}
	catch (const std::exception &e)
	{
		Logger::getInstance().error("连接数据库失败:%s", e.what());
		return false;
	}

	//检查心跳
	eventDispatcher_.addTimer(2000, [this](TimerWapper timer) {
		TCPServer_.checkConnection();
	});

	//用户登录
	messageMgr_.Register(CMD_DB_C_LOGIN_TOKEN, CALL_BACK_3(&DBServer::onUserLogin));
	//保存好友消息
	messageMgr_.Register(CMD_DB_C_SAVE_FRIEND_MESSAGE, CALL_BACK_3(&DBServer::onSaveFirendMessage));
	//加载好友列表
	messageMgr_.Register(CMD_DB_C_LOAD_FRIEND_LIST, CALL_BACK_3(&DBServer::onLoadFriendList));
	//加载群列表
	messageMgr_.Register(CMD_DB_C_LOAD_GROUP_LIST, CALL_BACK_3(&DBServer::onLoadGroupList));
	//保存群消息
	messageMgr_.Register(CMD_DB_C_SAVE_GROUP_MESSAGE, CALL_BACK_3(&DBServer::onSaveGroupMessage));
	return true;
}
bool DBServer::OnShutDown()
{
	Logger::getInstance().info("数据库服务器即将关闭");

	TCPServer_.close();

	CMYSQLPool::GetInstance()->UnInitialization();
	Logger::getInstance().stopLogger();
	return true;
}

void DBServer::onNewConnect(uint32_t socketID)
{
	Logger::getInstance().info("用户连接:%I64d", socketID);
}

void DBServer::onNewMessage(uint32_t socketID, uint32_t msgID, const void *data, size_t sz)
{
	Logger::getInstance().info("用户消息:socketID:%I64d, msgID:%d,size:%d", socketID, msgID, sz);

	try
	{
		std::string str((const char *)data, sz);
		auto doc = nlohmann::json::parse(str);

		uint32_t contextID = doc["contextID"];
		nlohmann::json data = doc["data"];

		if (messageMgr_.Invoke(msgID, socketID, contextID, data) == false)
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

void DBServer::onCloseConnect(uint32_t socketID)
{
	Logger::getInstance().info("用户断开连接:%d", socketID);
}

int DBServer::run()
{
	return eventDispatcher_.run();
}
void DBServer::sendData(uint32_t msgID, uint32_t socketID, uint32_t contextID, const nlohmann::json &msg)
{
	nlohmann::json doc;
	doc["contextID"] = contextID;
	doc["data"] = msg;

	TCPServer_.sendData(socketID, msgID, doc);
}
//用户登录
void DBServer::onUserLogin(uint32_t socketID, uint32_t contextID, const nlohmann::json &msg)
{
	struct DBOperator : public BaseDBOperator
	{
		DBOperator(uint32_t socketID, uint32_t contextID, const nlohmann::json &msg, DBServer *server)
			: BaseDBOperator(socketID, contextID, msg, server) {}

		/* data */
		void run()
		{
			try
			{
				int userID = data_["userID"];
				std::string token = data_["token"];

				auto conn = CMYSQLPool::GetInstance()->CreateMYSQLConn();
				auto query = conn->querySQL(fmt::format("call LoginByToken({},'{}')", userID, token).c_str());

				if (!query.eof())
				{
					int outCode = query.getIntField("outCode");
					std::string outString = query.getStringField("outString");

					//组装回复数据
					data_.clear();
					data_["code"] = outCode;
					data_["message"] = outString;
					if (outCode == 0)
					{
						data_["userID"] = query.getIntField("outUserid");
						data_["nickName"] = query.getStringField("outNickname");
						data_["headUrl"] = query.getStringField("outHead");
						data_["sex"] = query.getIntField("outSex");
					}
				}
			}
			catch (const std::exception &e)
			{
				data_.clear();
				data_["code"] = 100;
				data_["message"] = "数据库错误";

				Logger::getInstance().error("数据库 登录错误 %s", e.what());
			}
		}
		void prsentMainThread()
		{
			sendData(CMD_DB_S_LOGIN_RESULT, data_);
		}
	};

	threadPool_.addTask(new DBOperator(socketID, contextID, msg, this));
}

//加载好友列表
void DBServer::onLoadFriendList(uint32_t socketID, uint32_t contextID, const nlohmann::json &msg)
{
	struct DBOperator : public BaseDBOperator
	{
		DBOperator(uint32_t socketID, uint32_t contextID, const nlohmann::json &msg, DBServer *server)
			: BaseDBOperator(socketID, contextID, msg, server) {}

		/* data */
		void run()
		{
			try
			{
				int userID = data_["userID"];

				auto conn = CMYSQLPool::GetInstance()->CreateMYSQLConn();
				auto query = conn->querySQL(fmt::format("call LoadUserFriend({})", userID).c_str());

				//组装回复数据
				data_.clear();
				data_["code"] = 0;
				data_["message"] = "加载成功";
				data_["data"] = nlohmann::json::array();

				if (!query.eof())
				{
					nlohmann::json item;

					item["userID"] = query.getIntField("to_uid");
					item["nickName"] = query.getStringField("nickname");
					item["headUrl"] = query.getStringField("head");
					item["sex"] = query.getIntField("sex");
					item["alias"] = query.getStringField("alias");

					data_["data"].push_back(item);
				}

				//查询最大消息序列号
				for (int i = 0; i < data_["data"].size(); ++i)
				{
					nlohmann::json &info = data_["data"][i];
					int toUserID = info["userID"];
					query = conn->querySQL(fmt::format("call QueryFriendMessageID({},{})", userID, toUserID).c_str());
					long long messageIndex = 0;

					if (!query.eof())
					{
						messageIndex = query.getInt64Field("id");
					}
					info["messageIndex"] = messageIndex;
				}
			}
			catch (const std::exception &e)
			{
				data_.clear();
				data_["code"] = 100;
				data_["message"] = "数据库错误";

				Logger::getInstance().error("数据库 加载好友列表错误 %s", e.what());
			}
		}
		void prsentMainThread()
		{
			sendData(CMD_DB_S_LOAD_FRIEND_LIST_RESULT, data_);
		}
	};

	threadPool_.addTask(new DBOperator(socketID, contextID, msg, this));
}
//加载群列表
void DBServer::onLoadGroupList(uint32_t socketID, uint32_t contextID, const nlohmann::json &msg)
{
	struct tagGroupInfo
	{
		uint64_t groupID;
		std::string groupName;

		tagGroupInfo(uint64_t id, const std::string &name)
		{
			groupID = id;
			groupName = name;
		}
	};

	struct DBOperator : public BaseDBOperator
	{
		DBOperator(uint32_t socketID, uint32_t contextID, const nlohmann::json &msg, DBServer *server)
			: BaseDBOperator(socketID, contextID, msg, server) {}

		/* data */
		void run()
		{
			try
			{
				auto conn = CMYSQLPool::GetInstance()->CreateMYSQLConn();
				auto query = conn->querySQL("call LoadGroupList()");

				std::vector<tagGroupInfo> GroupInfos_;

				//加载所有群
				while (!query.eof())
				{
					uint64_t groupID = query.getInt64Field("groupid");
					std::string groupName = query.getStringField("groupname");
					GroupInfos_.emplace_back(groupID, groupName);

					query.nextRow();
				}

				//查找群成员
				for (const auto &v : GroupInfos_)
				{

					nlohmann::json doc;
					doc["groupID"] = v.groupID;
					doc["groupName"] = v.groupName;
					doc["members"] = nlohmann::json::array();

					auto query = conn->querySQL(fmt::format("call LoadGroupMember({})", v.groupID).c_str());
					while (!query.eof())
					{
						nlohmann::json item;

						item["userID"] = query.getIntField("uid");
						item["level"] = query.getIntField("level");
						item["groupNickName"] = query.getStringField("group_nickname");

						doc["members"].push_back(item);
						query.nextRow();
					}
					
					//查询消息ID
					long long messageIndex = 0;
					query = conn->querySQL(fmt::format("call QueryGroupMessageID({})", v.groupID).c_str());
					if (!query.eof())
					{
						messageIndex = query.getInt64Field("id");
					}
					doc["messageIndex"] = messageIndex;
		
					jsons_.push_back(doc);
				}
			}
			catch (const std::exception &e)
			{
				Logger::getInstance().error("数据库 加载群列表错误 %s", e.what());
			}
		}
		void prsentMainThread() override
		{
			for (const auto &v : jsons_)
				sendData(CMD_DB_S_LOAD_GROUP_LIST_RESULT, v);
		}

		std::vector<nlohmann::json> jsons_;
	};

	threadPool_.addTask(new DBOperator(socketID, contextID, msg, this));
}
//保存好友消息
void DBServer::onSaveFirendMessage(uint32_t socketID, uint32_t contextID, const nlohmann::json &msg)
{
	struct DBOperator : public BaseDBOperator
	{
		DBOperator(uint32_t socketID, uint32_t contextID, const nlohmann::json &msg, DBServer *server)
			: BaseDBOperator(socketID, contextID, msg, server) {}

		/* data */
		void run()
		{
			try
			{
				int userID = data_["userID"];
				int toUserID = data_["toUserID"];
				std::string content = data_["content"];
				int isRead = data_["isRead"];
				time_t currentTime = data_["currentTime"];
				long long messageIndex = data_["messageIndex"];

				auto conn = CMYSQLPool::GetInstance()->CreateMYSQLConn();
				conn->execSQL(fmt::format("call SaveFriendMessage({},{},{},'{}',{},{})", userID, toUserID, content, isRead, currentTime,messageIndex).c_str());
			}
			catch (const std::exception &e)
			{
				Logger::getInstance().error("数据库 保存好友聊天消息错误 %s", e.what());
			}
		}
	};

	threadPool_.addTask(new DBOperator(socketID, contextID, msg, this));
}

//保存群消息
void DBServer::onSaveGroupMessage(uint32_t socketID, uint32_t contextID, const nlohmann::json &msg)
{
	struct DBOperator : public BaseDBOperator
	{
		DBOperator(uint32_t socketID, uint32_t contextID, const nlohmann::json &msg, DBServer *server)
			: BaseDBOperator(socketID, contextID, msg, server) {}

		/* data */
		void run()
		{
			try
			{
				int userID = data_["fromUserID"];
				int groupID = data_["groupID"];
				std::string content = data_["content"];
				time_t currentTime = data_["currentTime"];
				long long messageIndex = data_["messageIndex"];

				auto conn = CMYSQLPool::GetInstance()->CreateMYSQLConn();
				conn->execSQL(fmt::format("call SaveGroupMessage({},{},'{}',{},{})", userID, groupID, content, currentTime,messageIndex).c_str());
			}
			catch (const std::exception &e)
			{
				Logger::getInstance().error("数据库 保存群聊天消息错误 %s", e.what());
			}
		}
	};

	threadPool_.addTask(new DBOperator(socketID, contextID, msg, this));
}