#include "Timer.h"

#include <uv.h>

struct uv_timer_req
{
	uv_timer_t t;
	TimerHandle cb;
	uint64_t n;
};

TimerWapper::TimerWapper(void* t)
	:timer_(t)
{

}

void TimerWapper::cancel()
{
	if (timer_ == nullptr) return;

	uv_timer_t* t = (uv_timer_t*)timer_;

	Timer* timer = (Timer*)t->data;
	timer->cancel(timer_);

	timer_ = nullptr;
}

uint64_t TimerWapper::runCount()
{
	if (timer_ == nullptr) return 0;
	uv_timer_req* req = (uv_timer_req*)timer_;
	return req->n;
}

Timer::Timer()
{
}

Timer::~Timer()
{
}

TimerWapper Timer::addTimer(uint64_t timeout, TimerHandle handle)
{
	uv_timer_req* req = new uv_timer_req;
	uv_timer_init(uv_default_loop(), &req->t);
	req->t.data = this;
	req->cb = handle;
	req->n = 0;

	timers_.insert(req);

	uv_timer_start((uv_timer_t*)req, [](uv_timer_t* handle)
	{
		uv_timer_req* req = (uv_timer_req*)handle;
		req->n++;
		req->cb(TimerWapper(req));

	}, timeout, timeout);

	return TimerWapper(req);
}

void Timer::close()
{
	auto tmp = timers_;
	for (const auto& v : tmp)
	{
		cancel(v);
	}
}

void Timer::cancel(void* t)
{
	auto iter = timers_.find(t);
	if (iter == timers_.end()) return;

	uv_timer_stop((uv_timer_t*)t);
	uv_close((uv_handle_t*)t, [](uv_handle_t* handle)
	{
		delete handle;
	});

	timers_.erase(iter);
}

