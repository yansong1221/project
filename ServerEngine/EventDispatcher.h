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

	//��ʱ��
	TimerWapper addTimer(uint64_t timeout, TimerHandle handle);

	//�ź����
	void addSignal(int signum, SignalHandle handle);
	void removeSignal(int signum);

	//�̳߳�
	void addTask(IThreadTask* task);
	void cancelTask(IThreadTask* task);

    int run();

	void close();
private:
	Timer timer_;
	Signal signal_;
	ThreadPool threadPool_;
};
