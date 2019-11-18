#pragma once

#include <string>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/reader.h>

#define	DEFAULT_BACKLOG_MAX					1024
//中心服务器端口
#define DEFAULT_CENTER_PORT					8100

//json 操作
inline bool ParseJson(const void* data, size_t sz, rapidjson::Document& Doc)
{
	Doc.Parse((const char*)data, sz);
	if (Doc.HasParseError()) return false;
	return true;
}
inline std::string writeJson(const rapidjson::Document& Doc)
{
	rapidjson::GenericStringBuffer<rapidjson::UTF8<>> buffer;
	rapidjson::Writer<rapidjson::GenericStringBuffer<rapidjson::UTF8<> >, rapidjson::UTF8<>, rapidjson::UTF8<>> writer(buffer);
	Doc.Accept(writer);

	return buffer.GetString();
}

struct JsonMessage
{
public:
	JsonMessage() :Allocator(Doc.GetAllocator()) {}
public:
	virtual std::string toJson() = 0;
	virtual void fromJson(const rapidjson::Document& Doc) = 0;
protected:
	rapidjson::Document Doc;
	rapidjson::Document::AllocatorType& Allocator;
};
//  [11/14/2019 yanso]


//内部消息
static const uint32_t INTERNAL_MESSAGE_START = 1;


