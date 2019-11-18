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

void CenterServer::onNewConnect(uint32_t socketID)
{
	ServerManager::getInstance()->createServer(socketID);
}

void CenterServer::onNewMessage(uint32_t socketID, uint32_t msgID, const void *data, size_t sz)
{
	auto iter = callBacks_.find(msgID);
	if(iter == callBacks_.end())
	{ 
		fprintf(stderr, "未注册的消息->msgID:%d", msgID);
		return;
	}

	rapidjson::Document Doc;
	Doc.Parse((const char*)data, sz);
	if (Doc.HasParseError()) return;

	for (const auto& v : iter->second)
	{
		v(socketID, Doc);
	}
}

void CenterServer::onCloseConnect(uint32_t socketID)
{
	ServerManager::getInstance()->discardServer(socketID);
}

void CenterServer::OnRegisterServer(uint32_t socketID, const rapidjson::Document& Doc)
{
	auto serverItem = ServerManager::getInstance()->serachServer(socketID);
	if (serverItem == nullptr)
	{
		Logger::getInstance().warning("服务器注册错误");
		return;
	}

	InternalServerRegister ServerRegister;
	ServerRegister.fromJson(Doc);
	serverItem->setServerInfo(ServerRegister.ip, ServerRegister.port, (ServerType)ServerRegister.serverType);

	Logger::getInstance().info("服务器注册成功->serverType:%d", ServerRegister.serverType);
}

void CenterServer::addReceiveCallBack(uint32_t msgID, ReceiveHandle handle)
{
	callBacks_[msgID].push_back(handle);
}

int CenterServer::run()
{
	return eventDispatcher_.run();
}

