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

void EventDispatcher::addSignal(int signum, SignalHandle handle)
{
	return signal_.add(signum, handle);
}

void EventDispatcher::removeSignal(int signum)
{
	return signal_.remove(signum);
}

void EventDispatcher::addTask(IThreadTask* task)
{
	return threadPool_.addTask(task);
}

void EventDispatcher::cancelTask(IThreadTask* task)
{
	return threadPool_.cancelTask(task);
}

int EventDispatcher::run()
{
   return uv_run(uv_default_loop(), UV_RUN_DEFAULT);
}

void EventDispatcher::close()
{
	timer_.close();
	signal_.close();
	threadPool_.close();

	uv_stop(uv_default_loop());
}
