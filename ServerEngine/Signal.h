#pragma once

#include "ServerEngine.h"
#include <functional>
#include <list>

using SignalHandle = std::function<void()>;

class ENGINE_API Signal
{
public:
	Signal();
	~Signal();
public:
	void add(int signum, SignalHandle handle);
	void remove(int signum);

	void close();
private:
	std::list<void*> sigs_;

};