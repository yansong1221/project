#include "DBServer.h"
#include "CMD.h"
#include <fmt/core.h>

#define DEFAULT_LISTEN_PORT				8100

struct BaseDBOperator : public IThreadTask
{
	BaseDBOperator(uint32_t socketID,uint32_t contextID,const nlohmann::json& msg,DBServer* server)
	:server_(server),
	socketID_(socketID),
	contextID_(contextID),
	data_(msg)
	{
		
	}

	void sendData(uint32_t msgID,const nlohmann::json& msg)
	{
		server_->sendData(msgID,socketID_,contextID_,msg);
	}

	uint32_t socketID_;
	uint32_t contextID_;
	DBServer* server_;
	nlohmann::json data_;
};

DBServer::DBServer()
	:eventDispatcher_(this),
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
	if(TCPServer_.listen(DEFAULT_LISTEN_PORT, 1024) == false) return false;

	try
	{
		CMYSQLPool::GetInstance()->Initialization("192.168.1.17",3306,"im","youxi","RGrSZfWZNtNRBbww");
	}
	catch(const std::exception& e)
	{
		Logger::getInstance().error("连接数据库失败:%s",e.what());
		return false;
	}
	

	//检查心跳
	eventDispatcher_.addTimer(2000, [this](TimerWapper timer)
	{
		TCPServer_.checkConnection();
	});

	//用户登录
	messageMgr_.Register(CMD_DB_C_LOGIN_TOKEN,CALL_BACK_3(&DBServer::onUserLogin));
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
	Logger::getInstance().info("用户消息:socketID:%I64d, msgID:%d,size:%d", socketID, msgID,sz);

	try
	{
		std::string str((const char*)data, sz);
		auto doc = nlohmann::json::parse(str);

		uint32_t contextID = doc["contextID"];
		nlohmann::json data = doc["data"];

		if (messageMgr_.Invoke(msgID,socketID,contextID, data) == false)
		{
			fprintf(stderr, "未注册的消息->msgID:%d", msgID);
			return;
		}
	}
	catch (const std::exception&)
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
void DBServer::sendData(uint32_t msgID, uint32_t socketID,uint32_t contextID,const nlohmann::json& msg)
{
	nlohmann::json doc;
	doc["contextID"] = contextID;
	doc["data"] = msg;

	TCPServer_.sendData(socketID,msgID,doc);
}
//用户登录
void DBServer::onUserLogin(uint32_t socketID,uint32_t contextID,const nlohmann::json& msg)
{
	struct DBOperator : public BaseDBOperator
	{
		DBOperator(uint32_t socketID,uint32_t contextID,const nlohmann::json& msg,DBServer* server)
		:BaseDBOperator(socketID,contextID,msg,server){}

		/* data */
		void run()
		{
			try
			{
				int userID = data_["userid"];
				std::string token = data_["token"];
				

				auto conn = CMYSQLPool::GetInstance()->CreateMYSQLConn();
				auto query = conn->querySQL(fmt::format("call LoginByToken({},'{}')",userID,token).c_str());

				if(!query.eof())
				{
					int outCode = query.getIntField("outCode");
					std::string outString = query.getStringField("outString");

					//组装回复数据
					data_.clear();
					data_["code"] = outCode;
					data_["message"] = outString;
					if(outCode == 0)
					{
						data_["userid"] = query.getIntField("outUserid");
						data_["nickname"] = query.getStringField("outNickname");
						data_["headUrl"] = query.getStringField("outHead");
						data_["sex"] = query.getStringField("outSex");
					}		
				}
				conn->commit();
			}
			catch(const std::exception& e)
			{
				data_.clear();
				data_["code"] = 100;
				data_["message"] = "数据库错误";

				Logger::getInstance().error("数据库 登录错误 %s",e.what());
			}
		}
		void prsentMainThread()
		{
			sendData(CMD_DB_S_LOGIN_RESULT,data_);	
		}
	};
	
	threadPool_.addTask(new DBOperator(socketID,contextID,msg,this));
}