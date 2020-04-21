#include "ServerManager.h"
#include <algorithm>

ServerManager* ServerManager::instance_ = nullptr;

ServerManager::ServerManager()
{

}

ServerManager::~ServerManager()
{
	clear();
}

ServerManager* ServerManager::getInstance()
{
	if (instance_ == nullptr) instance_ = new ServerManager;
	return instance_;
}

ServerItem* ServerManager::createServer(uint64_t socketID)
{
	auto item = new ServerItem(socketID);
	servers_.push_back(item);
	return item;
}

void ServerManager::discardServer(uint64_t socketID)
{
	auto iter = std::find_if(servers_.begin(), servers_.end(), [&](ServerItem* p)
	{
		return p->getSocketID() == socketID;
	});
	if (iter == servers_.end()) return;

	delete (*iter);
	servers_.erase(iter);
}

ServerItem* ServerManager::serachServer(uint64_t socketID)
{
	auto iter = std::find_if(servers_.begin(), servers_.end(), [&](ServerItem* p)
	{
		return p->getSocketID() == socketID;
	});

	if (iter == servers_.end()) return nullptr;
	return *iter;
}

void ServerManager::clear()
{
	for (const auto& v : servers_) delete v;
	servers_.clear();
}
