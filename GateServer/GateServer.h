#pragma once

#include "ServerEngine/ServerEngine.h"

class GateServer : public IEventDispatcher,public ITCPEvent
{
public:
	GateServer();
	~GateServer();

protected:
	virtual bool OnStartUp() override;
	virtual bool OnShutDown() override;


	virtual void onNewConnect(uint32_t socketID) override;
	virtual void onNewMessage(uint32_t socketID,uint32_t msgID ,const void *data, size_t sz) override;
	virtual void onCloseConnect(uint32_t socketID) override;

public:
	int run();

private:
	EventDispatcher eventDispatcher_;
	TCPServer		TCPServer_;
};