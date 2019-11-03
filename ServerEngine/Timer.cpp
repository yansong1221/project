#include "Timer.h"

#include <uv.h>

struct uv_timer_req
{
	uv_timer_t t;
	TimerHandle cb;
};

TimerWapper::TimerWapper(void* t)
	:timer_(t)
{

}

void TimerWapper::cancel()
{
	uv_timer_stop((uv_timer_t*)timer_);
	uv_close((uv_handle_t*)timer_, [](uv_handle_t* handle)
	{
		delete handle;
	});
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
	req->cb = handle;

	uv_timer_start((uv_timer_t*)req, [](uv_timer_t* handle)
	{
		uv_timer_req* req = (uv_timer_req*)handle;
		req->cb(TimerWapper(req));

	}, timeout, timeout);

	return TimerWapper(req);
}


