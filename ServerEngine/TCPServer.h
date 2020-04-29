
#pragma once

#include "ServerEngine.h"
#include "Connection.h"
#include "nlohmann_json.hpp"

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

	void sendData(uint32_t socketID, uint32_t msgID, const void* p, size_t n);
    void sendData(uint32_t socketID, uint32_t msgID,const nlohmann::json& msg);

	void closeSocket(uint32_t socketID);

	void checkConnection();
private:
	Connection *createConnection();
private:
    ITCPEvent *TCPEvent_;
	std::vector<Connection *> conns_;
	void* server_;
};
