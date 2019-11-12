#include "Logger.h"

#include <fmt/core.h>
#include <stdarg.h>
#include <iostream>

#ifdef _WIN32
#include <direct.h>
#else
#include<sys/stat.h>
#endif

#include <fstream>
#include <functional>

static Logger* g_Logger = nullptr;

static int mymkdir(const char* dirname)
{
	int ret = 0;
#ifdef _WIN32
	ret = mkdir(dirname);
#else
#ifdef unix
	ret = mkdir(dirname, 0775);
#endif
#endif
	return ret;
}

static int makedir(const char *newdir)
{
	char *buffer;
	char *p;
	int  len = (int)strlen(newdir);

	if (len <= 0)
		return 0;

	buffer = (char*)malloc(len + 1);
	strcpy(buffer, newdir);

	if (buffer[len - 1] == '/') {
		buffer[len - 1] = '\0';
	}
	if (mymkdir(buffer) == 0)
	{
		free(buffer);
		return 1;
	}

	p = buffer + 1;
	while (1)
	{
		char hold;

		while (*p && *p != '\\' && *p != '/')
			p++;
		hold = *p;
		*p = 0;
		if ((mymkdir(buffer) == -1) && (errno == ENOENT))
		{
			printf("couldn't create directory %s\n", buffer);
			free(buffer);
			return 0;
		}
		if (hold == 0)
			break;
		*p++ = hold;
	}
	free(buffer);
	return 1;
}
inline static std::string getLevelString(Logger::LogLevel level)
{
	switch (level)
	{
	case Logger::LOGLEVEL_INFO:
		return std::move(std::string("(Info):"));
		break;
	case Logger::LOGLEVEL_WARNING:
		return std::move(std::string("(Warning):"));
		break;
	case Logger::LOGLEVEL_ERROR:
		return std::move(std::string("(Error):"));
		break;
	default:
		break;
	}
	return std::move(std::string("(Unknown):"));
}

Logger::Logger()
	:runStatus_(false)
{

}

Logger::~Logger()
{
	
}

Logger& Logger::getInstance()
{
	if (g_Logger == nullptr)g_Logger = new Logger;
	return *g_Logger;
}

bool Logger::startLogger(const std::string& saveFileDir)
{
	if (runStatus_ == true) return false;
	runStatus_ = true;

	saveFileDir_ = saveFileDir;
	std::promise<bool> run;
	workThread_ = std::move(std::thread(std::bind(&Logger::threadFunc,this, std::ref(run))));
	return run.get_future().get();
}

void Logger::stopLogger()
{
	if (runStatus_ == false) return;
	runStatus_ = false;
	cv_.notify_all();
	workThread_.join();
}

void Logger::warning(const char* format, ...)
{
	if (runStatus_ == false) return;

	char buf[512];
	va_list argList;
	va_start(argList, format);
	vsnprintf(buf,sizeof(buf), format, argList);
	va_end(argList);

	pushLog(buf,LOGLEVEL_WARNING);
}

void Logger::error(const char* format, ...)
{
	if (runStatus_ == false) return;

	char buf[512];
	va_list argList;
	va_start(argList, format);
	vsnprintf(buf, sizeof(buf), format, argList);
	va_end(argList);

	pushLog(buf, LOGLEVEL_ERROR);
}

void Logger::info(const char* format, ...)
{
	if (runStatus_ == false) return;

	char buf[512];
	va_list argList;
	va_start(argList, format);
	vsnprintf(buf, sizeof(buf), format, argList);
	va_end(argList);

	pushLog(buf, LOGLEVEL_INFO);
}

void Logger::threadFunc(std::promise<bool>& run)
{
	run.set_value(true);

	while (runStatus_)
	{
		std::unique_lock<std::mutex> ul(mtx_);
		cv_.wait(ul, [this]()
		{
			return runStatus_ == false || logQue_.empty() == false;
		});
		ul.unlock();
		
		while (!logQue_.empty())
		{
			ul.lock();

			tagLogItem item = logQue_.front();
			logQue_.pop();

			ul.unlock();
			
			std::cout << item.outString << std::endl << std::flush;
			makedir(saveFileDir_.c_str());
			std::ofstream fout(saveFileDir_ + item.fileName, std::ios::ate | std::ios::app);
			fout << item.outString << std::endl;
			
		}
	
		if (runStatus_ == false) return;
	}	
}

void Logger::pushLog(const char* logString, LogLevel level)
{
	auto tt = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	struct tm* ptm = localtime(&tt);

	char buf[128];
	sprintf(buf, "%d-%02d-%02d-%02d:%02d:%02d",
		(int)ptm->tm_year + 1900, (int)ptm->tm_mon + 1, (int)ptm->tm_mday,
		(int)ptm->tm_hour, (int)ptm->tm_min, (int)ptm->tm_sec);

	int pos = 0;
	for (;;) 
	{
		if (buf[pos++] == ':')break;
	}

	std::string fileName = std::string(buf, pos - 1) + ".log";
	std::string outString = std::string("[") + buf + std::string("]:") + getLevelString(level) + logString;

	tagLogItem Item;
	Item.fileName = fileName;
	Item.outString = outString;

	std::unique_lock<std::mutex> ul(mtx_);
	logQue_.push(Item);
	ul.unlock();

	cv_.notify_all();
}
