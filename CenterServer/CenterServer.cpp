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


	addReceiveCallBack(INTERNAL_REGISTER_SERVER, std::bind(&CenterServer::OnRegisterServer, this, std::placeholders::_1, std::placeholders::_2));
	return true;
}

bool CenterServer::OnShutDown()
{
	TCPServer_.close();

	Logger::getInstance().stopLogger();
	ServerManager::getInstance()->clear();

	return true;
}

void CenterServer::onNewConnect(uint64_t socketID)
{
	ServerManager::getInstance()->createServer(socketID);
}

void CenterServer::onNewMessage(uint64_t socketID, uint32_t msgID, const void *data, size_t sz)
{
	auto iter = callBacks_.find(msgID);
	if(iter == callBacks_.end())
	{ 
		fprintf(stderr, "未注册的消息->msgID:%d", msgID);
		return;
	}

	try
	{
		std::string str((const char*)data, sz);
		auto doc = nlohmann::json::parse(str);

		for (const auto& handle : iter->second)
		{
			handle(socketID, doc);
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

void CenterServer::OnRegisterServer(uint64_t socketID, const nlohmann::json& Doc)
{
	auto serverItem = ServerManager::getInstance()->serachServer(socketID);
	if (serverItem == nullptr)
	{
		Logger::getInstance().warning("服务器注册错误");
		return;
	}

	std::string ip = Doc["ip"];
	int port = Doc["port"];
	int serverType = Doc["serverType"];

	serverItem->setServerInfo(ip, port, (ServerType)serverType);

	Logger::getInstance().info("服务器注册成功->serverType:%d", serverType);
}

void CenterServer::addReceiveCallBack(uint32_t msgID, ReceiveHandle handle)
{
	callBacks_[msgID].push_back(handle);
}

int CenterServer::run()
{
	return eventDispatcher_.run();
}

