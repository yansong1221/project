#include "EventDispatcher.h"
#include <uv.h>

EventDispatcher::EventDispatcher(/* args */)
{
}

EventDispatcher::~EventDispatcher()
{
}


TimerWapper EventDispatcher::addTimer(uint64_t timeout, TimerHandle handle)
{
	return timer_.addTimer(timeout, handle);
}

int EventDispatcher::run()
{
   return uv_run(uv_default_loop(), UV_RUN_DEFAULT);
}