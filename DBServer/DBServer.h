#pragma once
#include "ServerEngine/ServerEngine.h"
class DBServer : public IEventDispatcher,public ITCPEvent
{
public:
	DBServer();
	~DBServer();

protected:
	virtual bool OnStartUp() override;
	virtual bool OnShutDown() override;


	virtual void onNewConnect(uint64_t socketID) override;
	virtual void onNewMessage(uint64_t socketID, uint32_t msgID, const void *data, size_t sz) override;
	virtual void onCloseConnect(uint64_t socketID) override;
public:
	int run();

private:
	EventDispatcher eventDispatcher_;
	TCPServer TCPServer_;
};