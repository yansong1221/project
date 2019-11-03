#pragma once

#include "stdafx.h"

#include <functional>


class ENGINE_API TimerWapper
{
public:
	TimerWapper(void* t);

public:
	void cancel();
private:
	void* timer_;
};

using TimerHandle = std::function<void(TimerWapper)>;

class ENGINE_API Timer
{
public:
	Timer();
	~Timer();

public:

	TimerWapper addTimer(uint64_t timeout,TimerHandle handle);
};

