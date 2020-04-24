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

std::weak_ptr<ServerItem> ServerManager::createServer(uint64_t socketID)
{
	auto item = std::make_shared<ServerItem>(socketID);
	servers_.push_back(item);
	return std::weak_ptr<ServerItem>(item);
}

void ServerManager::discardServer(uint64_t socketID)
{
	auto iter = std::find_if(servers_.begin(), servers_.end(), [&](const auto& item)
	{
		return item->getSocketID() == socketID;
	});
	if (iter == servers_.end()) return;
	servers_.erase(iter);
}

std::weak_ptr<ServerItem> ServerManager::serachServer(uint64_t socketID)
{
	auto iter = std::find_if(servers_.begin(), servers_.end(), [&](const auto& item)
	{
		return item->getSocketID() == socketID;
	});

	if (iter == servers_.end()) return std::weak_ptr<ServerItem>();
	return *iter;
}

void ServerManager::clear()
{
	servers_.clear();
}
