#pragma once

#include "ServerEngine.h"

#include <string>
#include <queue>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <future>

class ENGINE_API Logger
{
public:

	enum LogLevel
	{
		LOGLEVEL_INFO,
		LOGLEVEL_WARNING,
		LOGLEVEL_ERROR,	
	};

	struct tagLogItem
	{
		std::string		outString;
		std::string		fileName;
	};

	Logger();
	~Logger();

public:
	static Logger& getInstance();

public:
	bool startLogger(const std::string& saveFileDir);
	void stopLogger();

	void warning(const char* format, ...);
	void error(const char* format, ...);
	void info(const char* format, ...);

private:
	void threadFunc(std::promise<bool>& run);
	void pushLog(const char* logString, LogLevel level);
private:
	std::string saveFileDir_;

	std::thread workThread_;
	std::condition_variable cv_;

	bool runStatus_;

	std::queue<tagLogItem> logQue_;
	std::mutex mtx_;
};