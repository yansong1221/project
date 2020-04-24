#pragma once
#include "ServerEngine.h"

#include <vector>
#include "MemoryStream.h"

class ENGINE_API ITCPEvent
{
public:
    virtual void onNewConnect(uint64_t socketID) = 0;
    virtual void onNewMessage(uint64_t socketID,uint32_t msgID, const void *data, size_t sz) = 0;
    virtual void onCloseConnect(uint64_t socketID) = 0;
};

class ENGINE_API Connection
{
private:
    /* data */
public:
    Connection(uint32_t bindIndex, ITCPEvent* handle);
    ~Connection();

public:
	uint64_t getSocketID() const;

    bool active() const;

    void send(uint32_t msgID,const void* p,size_t n);

    void close();

	uint32_t getRoundIndex() const;

	void attach(void* client);
	void check();
private:
	void parseDsata();
	void recvData();
private:
    uint32_t roundIndex_;
    uint32_t bindIndex_;

    bool active_;

	MemoryStream readBuf_;

	void* client_;
	ITCPEvent* TCPEvent_;
	int connStatus_;
};