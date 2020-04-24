#include "Signal.h"

#include <uv.h>
#include <algorithm>

struct uv_signal_req
{
	uv_signal_t t;
	int signum;
	SignalHandle cb;
};

Signal::Signal()
{

}

Signal::~Signal()
{

}

void Signal::add(int signum, SignalHandle handle)
{
	uv_signal_req* req = new uv_signal_req;
	uv_signal_init(uv_default_loop(), (uv_signal_t*)req);
	req->signum = signum;
	req->cb = handle;
	req->t.data = this;

	sigs_.push_back(req);

	uv_signal_start((uv_signal_t*)req, 
	[](uv_signal_t* handle, int signum)
	{
		uv_signal_req* req = (uv_signal_req*)handle;
		if (req->signum != signum) return;
		req->cb();

	}, signum);
}

void Signal::remove(int signum)
{
	auto iter = std::find_if(sigs_.begin(), sigs_.end(), [&](void* p)
	{
		uv_signal_req* req = (uv_signal_req*)p;
		return req->signum == signum;
	});

	if (iter == sigs_.end()) return;

	uv_signal_stop((uv_signal_t*)*iter);
	uv_close((uv_handle_t*)*iter, 
	[](uv_handle_t* handle)
	{
		delete handle;
	});

	sigs_.erase(iter);
}

void Signal::close()
{
	auto tmp = sigs_;
	for (const auto& v : tmp)
	{
		uv_signal_req* req = (uv_signal_req*)v;
		remove(req->signum);
	}
}
