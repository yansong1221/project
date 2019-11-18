#pragma once

#include "ServerEngine/ServerEngine.h"
#include <rapidjson/document.h>
#include <map>
#include <list>

using ReceiveHandle = std::function<void(uint32_t,const rapidjson::Document&)>;

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
	//×¢²á·þÎñÆ÷
	void OnRegisterServer(uint32_t socketID,const rapidjson::Document& Doc);
private:
	void addReceiveCallBack(uint32_t msgID, ReceiveHandle handle);
public:
	int run();

private:
	EventDispatcher eventDispatcher_;
	TCPServer		TCPServer_;

	std::map<uint32_t, std::list<ReceiveHandle>> callBacks_;
};