#include "EventDispatcher.h"
#include <uv.h>

EventDispatcher::EventDispatcher(IEventDispatcher* handle)
	:eventHandle_(handle)
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
	if (eventHandle_->OnStartUp() == false)
	{
		eventHandle_->OnShutDown();
		return -1;
	}

	addSignal(SIGINT, [this]() 
	{
		close(); 
	});
	addSignal(SIGKILL, [this]() 
	{
		close(); 
	});

	auto code = uv_run(uv_default_loop(), UV_RUN_DEFAULT);
	uv_loop_close(uv_default_loop());
	
	return code;
}

void EventDispatcher::close()
{
	if (eventHandle_->OnShutDown() == false)
	{
		return;
	}

	timer_.close();
	signal_.close();
	threadPool_.close();

	uv_stop(uv_default_loop());
}
