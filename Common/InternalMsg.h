#pragma once

#include "Define.h"

enum InternalMsgDefine
{
	INTERNAL_REGISTER_SERVER = INTERNAL_MESSAGE_START,
};

#pragma pack(1)

struct InternalServerRegister : public JsonMessage
{
	std::string ip;
	int	port;
	int serverType;

	virtual std::string toJson() override
	{
		Doc.SetObject();
		Doc.AddMember("ip", rapidjson::StringRef(ip.c_str()), Allocator);
		Doc.AddMember("port", port, Allocator);
		Doc.AddMember("serverType", serverType, Allocator);

		return std::move(writeJson(Doc));
	}
	virtual void fromJson(const rapidjson::Document& Doc) override
	{
		ip = Doc["ip"].GetString();
		port = Doc["port"].GetInt();
		serverType = Doc["serverType"].GetInt();
	}
};

#pragma pack()