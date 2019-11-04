#pragma once

#include "ServerEngine.h"

#include <functional>
#include <set>

class ENGINE_API TimerWapper
{
public:
	TimerWapper(void* t);

public:
	void cancel();

	uint64_t runCount();
private:
	void* timer_;
};

using TimerHandle = std::function<void(TimerWapper)>;

class ENGINE_API Timer
{
	friend class TimerWapper;
public:
	Timer();
	~Timer();

public:

	TimerWapper addTimer(uint64_t timeout,TimerHandle handle);

	void close();

protected:
	void cancel(void* t);
private:
	std::set<void*> timers_;
};

