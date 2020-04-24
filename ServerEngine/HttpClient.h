#pragma once
#include "ServerEngine.h"
#include <string>

class ENGINE_API HttpClient
{
public:
	HttpClient();
	~HttpClient();

	
	std::string GetBody() const;
	std::string GetHeader() const;

	bool get(const std::string& url);
	bool post(const std::string& url,const std::string& body);
private:
	bool sendHttpRequest(const std::string& method, const std::string& url, const std::string& body = "");
private:
	std::string m_Headers;
	std::string m_Body;
};

