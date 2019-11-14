#include "CenterServer.h"

#define DEFAULT_LISTEN_PORT				8200

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
	Logger::getInstance().info("开始监听端口:%d", DEFAULT_LISTEN_PORT);
	if (TCPServer_.listen(DEFAULT_LISTEN_PORT, 1024) == false) return false;


	return true;
}

bool CenterServer::OnShutDown()
{
	TCPServer_.close();
	Logger::getInstance().stopLogger();
	return true;
}

void CenterServer::onNewConnect(uint32_t socketID)
{

}

void CenterServer::onNewMessage(uint32_t socketID, uint32_t msgID, const void *data, size_t sz)
{
	auto iter = callBacks_.find(msgID);
	if(iter == callBacks_.end())
	{ 
		fprintf(stderr, "未注册的消息->msgID:", msgID);
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

}

void CenterServer::addReceiveCallBack(uint32_t msgID, ReceiveHandle handle)
{
	callBacks_[msgID].push_back(handle);
}

int CenterServer::run()
{
	return eventDispatcher_.run();
}

