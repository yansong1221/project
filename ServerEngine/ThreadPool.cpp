#include "ThreadPool.h"
#include <uv.h>
#include <algorithm>

struct  uv_work_req
{
	uv_work_t work;
	void*	task;
	void*	threadPool;
};

ThreadPool::ThreadPool()
{

}

ThreadPool::~ThreadPool()
{

}

void ThreadPool::addTask(IThreadTask* task)
{
	uv_work_req* work_req = (uv_work_req*)malloc(sizeof(uv_work_req));
	
	work_req->task = task;
	work_req->threadPool = this;

	tasks_.push_back(work_req);

	uv_queue_work(uv_default_loop(), (uv_work_t*)work_req,
	[](uv_work_t* req)
	{
		uv_work_req* work_req = (uv_work_req*)req;
		IThreadTask* task = (IThreadTask*)work_req->task;
		task->run();
	},
	[](uv_work_t* req, int status)
	{
		uv_work_req* work_req = (uv_work_req*)req;
		IThreadTask* task = (IThreadTask*)work_req->task;
		ThreadPool* threadPool = (ThreadPool*)work_req->threadPool;

		if (status == UV_ECANCELED)
		{
			fprintf(stderr, "Calculation of %d cancelled.\n", *(int *)req->data);
		}
		else
		{	
			task->prsentMainThread();
		}

		auto iter = std::find(threadPool->tasks_.begin(), threadPool->tasks_.end(), req);
		threadPool->tasks_.erase(iter);

		delete task;
		delete req;
	});
}

void ThreadPool::cancelTask(IThreadTask* task)
{
	auto iter = std::find_if(tasks_.begin(), tasks_.end(), 
		[&](void * p)
	{
		uv_work_req *work_req = (uv_work_req*)p;
		if (work_req->task == task) return true;
		return false;
	});

	if (iter != tasks_.end())
	{
		uv_cancel((uv_req_t*)*iter);
	} 
}

void ThreadPool::close()
{
	for (const auto& v : tasks_)
	{
		uv_cancel((uv_req_t*)v);
	}
}
