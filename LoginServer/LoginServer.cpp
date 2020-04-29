#include "LoginServer.h"
#include <functional>
#include "CMD.h"
#include "Common/Define.h"
#include "DBServer/CMD.h"

LoginServer::LoginServer()
	:eventDispatcher_(this),
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

	DBClient_.setConnectHandle(std::bind(&LoginServer::OnDBConnect, this,std::placeholders::_1));
	DBClient_.setReadHandle(std::bind(&LoginServer::OnDBMessage, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
	DBClient_.setCloseHandle(std::bind(&LoginServer::OnDBDisconnect, this));
	DBClient_.connect("127.0.0.1", 8100);

	Logger::getInstance().info("正在监听端口:%d",10000);
	if(TCPServer_.listen(10000, 1024) == false) return false;

	//注册网络消息

	//通过token登录
	messageMgr_.Register(CMD_LOGIN_C_LOGIN_TOKEN,CALL_BACK_2(&LoginServer::OnUserLogin));


	//注册数据库回复消息
	DBMessageMgr_.Register(CMD_DB_S_LOGIN_RESULT,CALL_BACK_2(&LoginServer::onDBLoginResult));
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
		std::string str((const char*)data, sz);
		auto doc = nlohmann::json::parse(str);

		uint32_t contextID = doc["contextID"];
		nlohmann::json data = doc["data"];

		if (messageMgr_.Invoke(msgID,socketID, doc) == false)
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
void LoginServer::onCloseConnect(uint32_t socketID)
{

}

void LoginServer::OnDBConnect(bool success)
{
	Logger::getInstance().info("连接数据库服务器结果:%d", success);

	nlohmann::json doc;
	doc["userid"] = 14525;
	doc["token"] = "1AB55609-C2B8-48BC-6886-108CA9D06B70";
	sendDBMessage(CMD_DB_C_LOGIN_TOKEN,100,doc);
}

void LoginServer::OnDBMessage(uint32_t msgID, const void* data, size_t sz)
{
	try
	{
		std::string str((const char*)data, sz);
		auto doc = nlohmann::json::parse(str);

		uint32_t contextID = doc["contextID"];
		nlohmann::json data = doc["data"];
		
		if (DBMessageMgr_.Invoke(msgID,contextID, data) == false)
		{
			fprintf(stderr, "未注册的数据库回复消息->msgID:%d", msgID);
			return;
		}
	}
	catch (const std::exception&)
	{
		return;
	}
}

void LoginServer::OnDBDisconnect()
{
	Logger::getInstance().info("数据库断开连接");
}
void LoginServer::sendDBMessage(uint32_t msgID,uint32_t contextID,const nlohmann::json& msg)
{
	nlohmann::json doc;
	doc["contextID"] = contextID;
	doc["data"] = msg;

	DBClient_.sendData(msgID,doc);
}

int LoginServer::run()
{
	return eventDispatcher_.run();
}

void LoginServer::OnUserLogin(uint32_t socketID,const nlohmann::json& msg)
{
	auto user = userManager_.searchUserBySocketID(socketID);
	if(user != nullptr)
	{
		nlohmann::json doc;
		doc["code"] = 101;
		doc["message"] = "您已经登录过了，不要重复登录！";
		TCPServer_.sendData(socketID,CMD_LOGIN_S_LOGIN_FAILD,doc);
		return;
	}

	sendDBMessage(CMD_DB_C_LOGIN_TOKEN,socketID,msg);
}

//登录结果
void LoginServer::onDBLoginResult(uint32_t contextID,const nlohmann::json& msg)
{
	Logger::getInstance().info(msg.dump().c_str());

	int code = msg["code"];
	std::string message = msg["message"];

	//登录失败
	if(code != 0)
	{
		TCPServer_.sendData(contextID,CMD_LOGIN_S_LOGIN_FAILD,msg);
		return;
	}

	//重复登录 不处理
	auto user = userManager_.searchUserBySocketID(contextID);
	if(user != nullptr)
	{
		return;
	}

	//创建登录成功实例
	UserInfo userInfo;
	userInfo.userID = msg["userid"];
	userInfo.sex =  msg["sex"];
	userInfo.nickName = msg["nickname"];
	userInfo.headUrl = msg["headUrl"];
	user = userManager_.createUser(contextID,userInfo);


	TCPServer_.sendData(contextID,CMD_LOGIN_S_LOGIN_SUCCESS,msg);
}
