#include "GateServer.h"
GateServer::GateServer()
	:eventDispatcher_(this),
	TCPServer_(this)
{

}

GateServer::~GateServer()
{

}

bool GateServer::OnStartUp()
{
	Logger::getInstance().startLogger("./log/GateServer/");
	Logger::getInstance().info("初始化服务器");
	Logger::getInstance().info("开始监听端口:%d", 8800);
	TCPServer_.listen(8800, 1024);
	return true;
}

bool GateServer::OnShutDown()
{
	Logger::getInstance().info("正在关闭服务器");

	TCPServer_.close();
	Logger::getInstance().stopLogger();
	return true;
}

void GateServer::onNewConnect(uint64_t socketID)
{

}

void GateServer::onNewMessage(uint64_t socketID, uint32_t msgID, const void *data, size_t sz)
{

}

void GateServer::onCloseConnect(uint64_t socketID)
{

}

int GateServer::run()
{
	return eventDispatcher_.run();
}

