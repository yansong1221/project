#pragma once
#include "ServerEngine/ServerEngine.h"
#include "Common/Message.h"
#include "Common/Define.h"

using ReceiveHandle = std::function<void(uint32_t, uint32_t,const nlohmann::json&)>;

class DBServer : public IEventDispatcher,public ITCPEvent
{
	friend class BaseDBOperator;
public:
	DBServer();
	~DBServer();

protected:
	virtual bool OnStartUp() override;
	virtual bool OnShutDown() override;


	virtual void onNewConnect(uint32_t socketID) override;
	virtual void onNewMessage(uint32_t socketID, uint32_t msgID, const void *data, size_t sz) override;
	virtual void onCloseConnect(uint32_t socketID) override;

//查询数据库
protected:

	//用户登录
	void onUserLogin(uint32_t socketID,uint32_t contextID,const nlohmann::json& msg);
protected:
	
public:
	int run();

//内部函数
private:
	void sendData(uint32_t msgID,uint32_t socketID,uint32_t contextID,const nlohmann::json& msg);
private:
	EventDispatcher eventDispatcher_;
	TCPServer TCPServer_;

	MessageManager<ReceiveHandle> messageMgr_;
	ThreadPool threadPool_;
};