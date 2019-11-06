#pragma once

#ifdef BUILD_ENGINE_DLL
#pragma warning(disable:4251)
#pragma warning(disable:4099)
#define ENGINE_API  __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)

#include "Connection.h"
#include "EventDispatcher.h"
#include "HttpClient.h"
#include "MemoryStream.h"
#include "Signal.h"
#include "TCPServer.h"
#include "ThreadPool.h"
#include "Timer.h"
#include "TCPClient.h"
#endif