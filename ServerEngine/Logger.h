#pragma once

#include "ServerEngine.h"

#include <string>
#include <queue>
#include <thread>
#include <condition_variable>
#include <mutex>

class ENGINE_API Logger
{
public:

	enum LogMode
	{
		LOGGER_MODE_FILE,
		LOGGER_MODE_CONSOLE,
		LOGGER_MODE_BOTH,
	};

	struct tagLogItem
	{
		std::string saveFileDir;
		LogMode logMode;
		std::string logString;
	};

	Logger();
	~Logger();

public:
	static Logger& getInstance();

public:
	void startLogger(const std::string& saveFileDir, LogMode mode = LOGGER_MODE_BOTH);

	void warning(const char* format, ...);
	void error(const char* format, ...);
	void info(const char* format, ...);

private:
	void threadFunc();
	void pushLog(const std::string& logString);
private:
	LogMode logMode_;
	std::string saveFileDir_;

	std::thread workThread_;
	std::condition_variable cv_;

	bool runStatus_;

	std::queue<tagLogItem> logQue_;
	std::mutex mtx_;
};