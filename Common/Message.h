#pragma once

#include <map>
#include <algorithm>

template <class Func>
class MessageManager 
{
public:
	void Register(uint32_t msgID, Func func)
	{
		callBacks_[msgID].push_back(func);
	}

	template <class ...Args>
	bool Invoke(uint32_t msgID, Args ...args)
	{
		auto iter = callBacks_.find(msgID);
		if (iter == callBacks_.end()) return false;

		std::for_each(iter->second.begin(), iter->second.end(), [&](auto handle) 
		{
			handle(std::forward<Args>(args)...);
		});

		return true;
	}
private:
	std::map<uint32_t, std::list<Func>> callBacks_;
};