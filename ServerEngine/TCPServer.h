
#pragma once

#include "ServerEngine.h"
#include "Connection.h"

class ENGINE_API TCPServer
{
private:
    /* data */
public:
    TCPServer(ITCPEvent* handle);
    ~TCPServer();

public:
    bool listen(int port, int backlog);
    void close();

	void sendData(uint32_t socketID, const void* p, size_t n);

	void closeSocket(uint32_t socketID);
private:
	Connection *createConnection();
private:
    ITCPEvent *TCPEvent_;
	std::vector<Connection *> conns_;
	void* server_;
};
