#include "LoginServer.h"
#include <functional>

LoginServer::LoginServer()
	:eventDispatcher_(this)
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
	return true;
}

bool LoginServer::OnShutDown()
{
	DBClient_.close();
	Logger::getInstance().stopLogger();
	return true;
}

void LoginServer::OnDBConnect(bool success)
{
	Logger::getInstance().info("连接数据库服务器结果:%d", success);
}

void LoginServer::OnDBMessage(uint32_t msgID, const void* data, size_t sz)
{

}

void LoginServer::OnDBDisconnect()
{
	Logger::getInstance().info("数据库断开连接");
}

int LoginServer::run()
{
	return eventDispatcher_.run();
}
