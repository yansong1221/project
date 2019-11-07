#pragma once

#include "ServerEngine.h"
#include <string>
#include <functional>
#include <vector>

using ClientConnectHandle = std::function<void(bool)>;
using ClientReadHandle = std::function<void(uint32_t, const void *, size_t)>;
using ClientCloseHandle = std::function<void()>;

class ENGINE_API TCPClient
{
public:
	TCPClient();
	~TCPClient();

public:

	void connect(const std::string& host, int port);

	void setConnectHandle(ClientConnectHandle handle);
	void setReadHandle(ClientReadHandle handle);
	void setCloseHandle(ClientCloseHandle handle);

	void sendData(uint32_t msgID, const void* data, size_t sz);

	void close();
private:
	void parseDsata();
	void recvData();
private:
	void* client_;

	ClientConnectHandle connectHandle_;
	ClientReadHandle readHandle_;
	ClientCloseHandle closeHandle_;

	std::vector<char> readBuf_;
};