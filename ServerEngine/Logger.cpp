#include "Logger.h"

#include "fmt/core.h"
#include <stdarg.h>

static Logger g_Logger;

static const char* getCurrentTime()
{
	auto tt = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	struct tm* ptm = localtime(&tt);

	static char buf[128];
	sprintf(buf, "%d-%02d-%02d-%02d.%02d.%02d",
		(int)ptm->tm_year + 1900, (int)ptm->tm_mon + 1, (int)ptm->tm_mday,
		(int)ptm->tm_hour, (int)ptm->tm_min, (int)ptm->tm_sec);

	return buf;
}

Logger::Logger()
	:logMode_(LOGGER_MODE_BOTH),
	runStatus_(false)
{

}

Logger::~Logger()
{
	
}

Logger& Logger::getInstance()
{
	return g_Logger;
}

void Logger::startLogger(const std::string& saveFileDir, LogMode mode /*= LOGGER_MODE_BOTH*/)
{
	saveFileDir_ = saveFileDir;
	logMode_ = mode;

	workThread_ = std::move(std::thread(std::bind(&Logger::threadFunc,this)));
}

void Logger::warning(const char* format, ...)
{
	char buf[512];
	va_list argList;
	va_start(argList, format);
	vsnprintf(buf,sizeof(buf), format, argList);
	va_end(argList);

	std::string outLog = getCurrentTime();
	outLog.append(buf);

	pushLog(outLog);
}

void Logger::error(const char* format, ...)
{

}

void Logger::info(const char* format, ...)
{

}

void Logger::threadFunc()
{
	while (runStatus_)
	{
		std::unique_lock<std::mutex> ul(mtx_);
		cv_.wait(ul, [this]()
		{
			return runStatus_ == false || logQue_.empty() == false;
		});
		ul.unlock();
		if (runStatus_ == false) return;

		while (!logQue_.empty())
		{
			ul.lock();

			tagLogItem item = logQue_.back();
			logQue_.pop();

			ul.unlock();


		}
	}	
}

void Logger::pushLog(const std::string& logString)
{
	std::unique_lock<std::mutex> ul(mtx_);

	tagLogItem Item;
	Item.logMode = logMode_;
	Item.saveFileDir = saveFileDir_;
	Item.logString = logString;

	logQue_.push(std::move(Item));
}
