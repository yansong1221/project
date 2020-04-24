
#pragma once
#include <list>
#include "ServerItem.h"
class ServerManager
{
public:
	ServerManager();
	~ServerManager();

public:

	static ServerManager* getInstance();

	std::weak_ptr<ServerItem> createServer(uint64_t socketID);
	void discardServer(uint64_t socketID);
	
	std::weak_ptr<ServerItem> serachServer(uint64_t socketID);

	void clear();
private:
	static ServerManager* instance_;

	std::list<std::shared_ptr< ServerItem>> servers_;
};