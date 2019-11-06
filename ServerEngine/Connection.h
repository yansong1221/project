#pragma once
#include "ServerEngine.h"
#include <vector>

class ENGINE_API ITCPEvent
{
public:
    virtual void onNewConnect(uint32_t socketID) = 0;
    virtual void onNewMessage(uint32_t socketID,const void *p, size_t n) = 0;
    virtual void onCloseConnect(uint32_t socketID) = 0;
};

class ENGINE_API Connection
{
private:
    /* data */
public:
    Connection(uint16_t bindIndex, ITCPEvent* handle);
    ~Connection();

public:
    uint32_t getSocketID() const;

    bool active() const;

    void send(const void* p,size_t n);

    void close();

	uint16_t getRoundIndex() const;

	void attach(void* client);
private:
	void parseDsata();
	void recvData();
private:
    uint16_t roundIndex_;
    uint16_t bindIndex_;

    bool active_;

	std::vector<char> readBuf_;

	void* client_;

	ITCPEvent* TCPEvent_;
};