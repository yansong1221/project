#pragma once
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#pragma warning(disable:4251)
#pragma warning(disable:4099)
#endif

#pragma pack(1)
struct TCPHeader
{
	uint32_t	msgID;
	uint32_t	len;
};

#define ENGINE_PING_MSGID				1
#pragma pack()

#ifdef BUILD_ENGINE_DLL
	#ifdef _WIN32
		#define ENGINE_API  __declspec(dllexport)
	#else
		#define ENGINE_API
	#endif
		
#else
	#ifdef _WIN32
		#define ENGINE_API __declspec(dllimport)
	#else
		#define ENGINE_API
	#endif

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



