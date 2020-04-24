#include "CenterServer.h"
#include "ServerManager.h"

#include <Common/InternalMsg.h>

CenterServer::CenterServer()
	:eventDispatcher_(this),
	TCPServer_(this)
{

}

CenterServer::~CenterServer()
{

}

bool CenterServer::OnStartUp()
{
	Logger::getInstance().startLogger("./log/CenterServer/");
	Logger::getInstance().info("初始化服务器");
	Logger::getInstance().info("开始监听端口:%d", DEFAULT_CENTER_PORT);
	if (TCPServer_.listen(DEFAULT_CENTER_PORT, DEFAULT_BACKLOG_MAX) == false) return false;


	messageMgr_.Register(REGISTER_SERVER, CALL_BACK_2(&CenterServer::OnRegisterServer));
	return true;
}

bool CenterServer::OnShutDown()
{
	TCPServer_.close();
	ServerManager::getInstance()->clear();

	Logger::getInstance().stopLogger();
	return true;
}

void CenterServer::onNewConnect(uint64_t socketID)
{
	ServerManager::getInstance()->createServer(socketID);
}

void CenterServer::onNewMessage(uint64_t socketID, uint32_t msgID, const void *data, size_t sz)
{
	try
	{
		std::string str((const char*)data, sz);
		auto doc = nlohmann::json::parse(str);
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

void CenterServer::onCloseConnect(uint64_t socketID)
{
	ServerManager::getInstance()->discardServer(socketID);
}

void CenterServer::OnRegisterServer(uint64_t socketID, const nlohmann::json& msg)
{
	auto serverItem = ServerManager::getInstance()->serachServer(socketID).lock();
	if (serverItem == nullptr)
	{
		Logger::getInstance().warning("服务器注册错误");
		return;
	}

	std::string ip = msg["ip"];
	int port = msg["port"];
	int serverType = msg["serverType"];

	serverItem->setServerInfo(ip, port, (ServerType)serverType);

	Logger::getInstance().info("服务器注册成功->serverType:%d", serverType);
}

int CenterServer::run()
{
	return eventDispatcher_.run();
}

