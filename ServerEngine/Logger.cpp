#include "Logger.h"

#include "fmt/core.h"

static Logger g_Logger;

Logger::Logger()
	:logMode_(LOGGER_MODE_BOTH),
	runStatus_(false)
{

}

Logger::~Logger()
{
	uv_fs_write
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

	fmt::format()
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
		if (runStatus_ == false) return;
		ul.unlock();

		while (!logQue_.empty())
		{
			ul.lock();

			tagLogItem item = logQue_.back();
			logQue_.pop();

			ul.unlock();



		}
	}	
}
