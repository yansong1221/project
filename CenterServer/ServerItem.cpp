#include "ServerItem.h"

ServerItem::ServerItem(uint64_t socketID)
	:serverType_(SERVER_TYPE_NONE),
	port_(0),
	socketID_(socketID)
{

}

ServerItem::~ServerItem()
{

}

void ServerItem::setServerInfo(const std::string& ip, int port, ServerType type)
{
	ipAddress_ = ip;
	port_ = port;
	serverType_ = type;
}

std::string ServerItem::getAddress() const
{
	return ipAddress_;
}

int ServerItem::getPort() const
{
	return port_;
}

uint64_t ServerItem::getSocketID() const
{
	return socketID_;
}

ServerType ServerItem::getServerType() const
{
	return serverType_;
}
