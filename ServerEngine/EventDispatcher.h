#pragma once

#include "stdafx.h"
#include "Timer.h"
class ENGINE_API EventDispatcher
{
private:
    /* data */
public:
    EventDispatcher(/* args */);
    ~EventDispatcher();

public:
	TimerWapper addTimer(uint64_t timeout, TimerHandle handle);
    int run();


private:
	Timer timer_;
};
