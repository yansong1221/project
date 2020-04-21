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
	Logger::getInstance().info("初始化服务器");
	Logger::getInstance().info("开始监听端口:%d", DEFAULT_LISTEN_PORT);
	if(TCPServer_.listen(DEFAULT_LISTEN_PORT, 1024) == false) return false;

	HttpClient client;
	client.sendHttpRequest("GET", "https://www.baidu.com");

	Logger::getInstance().info(client.GetBody().c_str());
	//检查心跳
	eventDispatcher_.addTimer(2000, [this](TimerWapper timer)
	{
		TCPServer_.checkConnection();
	});

	return true;
}
bool DBServer::OnShutDown()
{
	Logger::getInstance().info("数据库服务器即将关闭");
	
	TCPServer_.close();
	Logger::getInstance().stopLogger();
	return true;
}

void DBServer::onNewConnect(uint64_t socketID)
{
	Logger::getInstance().info("用户连接:%d", socketID);
}

void DBServer::onNewMessage(uint64_t socketID, uint32_t msgID, const void *data, size_t sz)
{
	Logger::getInstance().info("用户消息:socketID:%d, msgID:%d,size:%d", socketID, msgID,sz);
}

void DBServer::onCloseConnect(uint64_t socketID)
{
	Logger::getInstance().info("用户断开连接:%d", socketID);
}

int DBServer::run()
{
	return eventDispatcher_.run();
}
