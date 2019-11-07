#pragma once
#include <stdint.h>

#pragma warning(disable:4251)
#pragma warning(disable:4099)

#ifdef BUILD_ENGINE_DLL
#define ENGINE_API  __declspec(dllexport)
#pragma pack(1)

struct TCPHeader
{
	uint32_t	msgID;
	uint32_t	len;
};

#pragma pack()
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
#include "Logger.h"
#endif