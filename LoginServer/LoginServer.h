#pragma once

#include "ServerEngine/ServerEngine.h"

class LoginServer:public IEventDispatcher
{
public:
	LoginServer();
	~LoginServer();

protected:
	virtual bool OnStartUp() override;
	virtual bool OnShutDown() override;

//数据库事件处理
protected:
	void OnDBConnect(bool success);
	void OnDBMessage(uint32_t msgID, const void* data, size_t sz);
	void OnDBDisconnect();
public:
	int run();
private:
	EventDispatcher eventDispatcher_;
	TCPClient DBClient_;
};