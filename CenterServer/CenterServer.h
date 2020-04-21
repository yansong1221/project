#pragma once

#include "ServerEngine/ServerEngine.h"
#include "nlohmann_json.hpp"
#include <map>
#include <list>

using ReceiveHandle = std::function<void(uint64_t,const nlohmann::json&)>;

class CenterServer : public IEventDispatcher, public ITCPEvent
{
public:
	CenterServer();
	~CenterServer();

protected:
	virtual bool OnStartUp() override;
	virtual bool OnShutDown() override;


	virtual void onNewConnect(uint64_t socketID) override;
	virtual void onNewMessage(uint64_t socketID, uint32_t msgID, const void *data, size_t sz) override;
	virtual void onCloseConnect(uint64_t socketID) override;

private:
	//×¢²á·þÎñÆ÷
	void OnRegisterServer(uint64_t socketID, const nlohmann::json& Doc);
private:
	void addReceiveCallBack(uint32_t msgID, ReceiveHandle handle);
public:
	int run();

private:
	EventDispatcher eventDispatcher_;
	TCPServer		TCPServer_;

	std::map<uint32_t, std::list<ReceiveHandle>> callBacks_;
};