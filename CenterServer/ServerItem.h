#pragma once

#include <string>

enum ServerType
{
	SERVER_TYPE_NONE,
	SERVER_TYPE_LOGIN,
	SERVER_TYPE_GATE,
};

class ServerItem : public std::enable_shared_from_this<ServerItem>
{
public:
	ServerItem(uint64_t socketID);
	~ServerItem();

public:
	void setServerInfo(const std::string& ip,int port, ServerType type);

	std::string getAddress() const;
	int getPort() const;

	uint64_t getSocketID() const;
	ServerType getServerType() const;
private:
	std::string	ipAddress_;
	int port_;
	ServerType serverType_;
	uint64_t socketID_;
};