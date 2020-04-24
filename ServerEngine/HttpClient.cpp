
#include "HttpClient.h"
#include <curl/curl.h>
#include <string>

static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
	std::string *recvBuffer = (std::string*)stream;
	size_t sizes = size * nmemb;

	// add data to the end of recvBuffer
	// write data maybe called more than once in a single request
	recvBuffer->insert(recvBuffer->end(), (char*)ptr, (char*)ptr + sizes);

	return sizes;
}
HttpClient::HttpClient()
{

}


HttpClient::~HttpClient()
{
}
bool HttpClient::get(const std::string& url)
{
	return sendHttpRequest("GET",url);
}
bool HttpClient::post(const std::string& url,const std::string& body)
{
	return sendHttpRequest("POST",url);
}
bool HttpClient::sendHttpRequest(const std::string& method, const std::string& url, const std::string& body)
{
	m_Headers.clear();
	m_Body.clear();

	CURL* pCurl = curl_easy_init();

	curl_easy_setopt(pCurl, CURLOPT_URL, url.c_str());

	curl_easy_setopt(pCurl, CURLOPT_WRITEFUNCTION, write_data);
	curl_easy_setopt(pCurl, CURLOPT_WRITEDATA, &m_Body);

	curl_easy_setopt(pCurl, CURLOPT_HEADERFUNCTION, write_data);
	curl_easy_setopt(pCurl, CURLOPT_HEADERDATA, &m_Headers);

	
	if (method == "POST")
	{
		curl_easy_setopt(pCurl, CURLOPT_POST, 1);
		curl_easy_setopt(pCurl, CURLOPT_POSTFIELDS, body.data());
		curl_easy_setopt(pCurl, CURLOPT_POSTFIELDSIZE, body.size());
	}
	curl_easy_perform(pCurl);

	long responseCode;
	CURLcode code = curl_easy_getinfo(pCurl, CURLINFO_RESPONSE_CODE, &responseCode);
	if (code != CURLE_OK || !(responseCode >= 200 && responseCode < 300)) {

		curl_easy_cleanup(pCurl);
		return false;
	}
	curl_easy_cleanup(pCurl);
	return true;
}

std::string HttpClient::GetBody() const
{
	return m_Body;
}

std::string HttpClient::GetHeader() const
{
	return m_Headers;
}
