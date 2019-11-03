#include "EventDispatcher.h"
#include <uv.h>

EventDispatcher::EventDispatcher(/* args */)
{
}

EventDispatcher::~EventDispatcher()
{
}

int EventDispatcher::run()
{
   return uv_run(uv_default_loop(), UV_RUN_DEFAULT);
}