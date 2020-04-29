#pragma once

#include "ServerEngine/ServerEngine.h"
#include "Common/Message.h"
#include "UserManager.h"

using ReceiveHandle = std::function<void(uint32_t,const nlohmann::json&)>;
using DBReceiveHandle = std::function<void(uint32_t,const nlohmann::json&)>;

class LoginServer:public IEventDispatcher,public ITCPEvent
{
public:
	LoginServer();
	~LoginServer();

protected:
	virtual bool OnStartUp() override;
	virtual bool OnShutDown() override;

	virtual void onNewConnect(uint32_t socketID) override;
	virtual void onNewMessage(uint32_t socketID, uint32_t msgID, const void *data, size_t sz) override;
	virtual void onCloseConnect(uint32_t socketID) override;

//数据库事件处理
protected:
	void OnDBConnect(bool success);
	void OnDBMessage(uint32_t msgID, const void* data, size_t sz);
	void OnDBDisconnect();

	void sendDBMessage(uint32_t msgID,uint32_t contextID,const nlohmann::json& msg);
//数据库服务器回复消息
protected:
	//登录结果
	void onDBLoginResult(uint32_t contextID,const nlohmann::json& msg);

//网络消息
private:
	//用户登录
	void OnUserLogin(uint32_t socketID,const nlohmann::json& msg);
public:
	int run();
private:
	TCPServer TCPServer_;
	EventDispatcher eventDispatcher_;
	TCPClient DBClient_;

	MessageManager<ReceiveHandle> messageMgr_;
	MessageManager<DBReceiveHandle> DBMessageMgr_;

	UserManager userManager_;
	
};