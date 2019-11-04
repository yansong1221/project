#pragma once

#include "ServerEngine.h"

#include <list>

class IThreadTask
{
public:

	virtual ~IThreadTask() {}

	virtual void run() = 0;
	void prsentMainThread(){}
};

class ENGINE_API ThreadPool
{
public:
	ThreadPool();
	~ThreadPool();

public:
	void addTask(IThreadTask* task);

	void cancelTask(IThreadTask* task);

	void close();

private:
	std::list<void*> tasks_;
};