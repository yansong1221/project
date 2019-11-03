
#pragma once

#include "Connection.h"

class TCPServer
{
private:
    /* data */
public:
    TCPServer(/* args */);
    ~TCPServer();

public:
    bool listen(int port, int backlog);
    void close();
    void setEventHandle(ITCPEvent* handle);
private:
    ConnectionMgr connMgr_;
    ITCPEvent *TCPEvent_;
};
