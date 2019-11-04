#pragma once

#include "ServerEngine.h"
#include "Timer.h"
#include "Signal.h"
#include "ThreadPool.h"

class ENGINE_API EventDispatcher
{
private:
    /* data */
public:
    EventDispatcher(/* args */);
    ~EventDispatcher();

public:

	//定时器
	TimerWapper addTimer(uint64_t timeout, TimerHandle handle);

	//信号相关
	void addSignal(int signum, SignalHandle handle);
	void removeSignal(int signum);

	//线程池
	void addTask(IThreadTask* task);
	void cancelTask(IThreadTask* task);

    int run();

	void close();
private:
	Timer timer_;
	Signal signal_;
	ThreadPool threadPool_;
};
