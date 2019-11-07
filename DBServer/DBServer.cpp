#include "DBServer.h"

#define DEFAULT_LISTEN_PORT				8100

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
	Logger::getInstance().info("��ʼ��������");

	Logger::getInstance().info("��ʼ�����˿�:%d", DEFAULT_LISTEN_PORT);
	if(TCPServer_.listen(DEFAULT_LISTEN_PORT, 1024) == false) return false;

	//�������
	eventDispatcher_.addTimer(2000, [this](TimerWapper timer)
	{
		TCPServer_.checkConnection();
	});

	return true;
}
bool DBServer::OnShutDown()
{
	Logger::getInstance().stopLogger();
	return true;
}

void DBServer::onNewConnect(uint32_t socketID)
{
	Logger::getInstance().info("�û�����:%d", socketID);
}

void DBServer::onNewMessage(uint32_t socketID, uint32_t msgID, const void *data, size_t sz)
{
	Logger::getInstance().info("�û���Ϣ:socketID:%d, msgID:%d,size:%d", socketID, msgID,sz);
}

void DBServer::onCloseConnect(uint32_t socketID)
{
	Logger::getInstance().info("�û��Ͽ�����:%d", socketID);
}

int DBServer::run()
{
	return eventDispatcher_.run();
}
