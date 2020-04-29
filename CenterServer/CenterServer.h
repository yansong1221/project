#pragma once

#include "ServerEngine/ServerEngine.h"
#include "Common/Message.h"

#include <map>
#include <list>


using ReceiveHandle = std::function<void(uint32_t,const nlohmann::json&)>;

class CenterServer : public IEventDispatcher, public ITCPEvent
{
public:
	CenterServer();
	~CenterServer();

protected:
	virtual bool OnStartUp() override;
	virtual bool OnShutDown() override;


	virtual void onNewConnect(uint32_t socketID) override;
	virtual void onNewMessage(uint32_t socketID, uint32_t msgID, const void *data, size_t sz) override;
	virtual void onCloseConnect(uint32_t socketID) override;

private:
	//注册服务器
	void OnRegisterServer(uint32_t socketID, const nlohmann::json& msg);
public:
	int run();

private:
	EventDispatcher eventDispatcher_;
	TCPServer		TCPServer_;

	MessageManager<ReceiveHandle> messageMgr_;
};