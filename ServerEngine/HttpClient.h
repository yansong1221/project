#pragma once
#include "stdafx.h"
#include <string>

class ENGINE_API HttpClient
{
public:
	HttpClient();
	~HttpClient();

	bool sendHttpRequest(const std::string& method, const std::string& url, const std::string& uri = "", const std::string& query = "", const std::string& body = "");
	std::string GetBody() const;
	std::string GetHeader() const;
private:
	std::string m_Headers;
	std::string m_Body;
};

