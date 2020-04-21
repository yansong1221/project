
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

	ServerItem* createServer(uint64_t socketID);
	void discardServer(uint64_t socketID);
	
	ServerItem* serachServer(uint64_t socketID);

	void clear();
private:
	static ServerManager* instance_;

	std::list<ServerItem*> servers_;
};