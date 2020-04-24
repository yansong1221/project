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

