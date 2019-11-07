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
	Logger::getInstance().info("��ʼ��������");
	Logger::getInstance().info("��ʼ�����˿�:%d", 8800);
	TCPServer_.listen(8800, 1024);
	return true;
}

bool GateServer::OnShutDown()
{
	Logger::getInstance().info("���ڹرշ�����");

	TCPServer_.close();
	Logger::getInstance().stopLogger();
	return true;
}

void GateServer::onNewConnect(uint32_t socketID)
{

}

void GateServer::onNewMessage(uint32_t socketID, const void *p, size_t n)
{

}

void GateServer::onCloseConnect(uint32_t socketID)
{

}

int GateServer::run()
{
	return eventDispatcher_.run();
}

