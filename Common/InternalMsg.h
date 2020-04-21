#pragma once

#include "Define.h"

#define CALL_BACK_1(FUNC) std::bind(FUNC,this,std::placeholders::_1)
#define CALL_BACK_2(FUNC) std::bind(FUNC,this,std::placeholders::_1,std::placeholders::_2)
#define CALL_BACK_3(FUNC) std::bind(FUNC,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3)

enum InternalMsg
{
	REGISTER_SERVER = INTERNAL_MESSAGE_START,
};

#pragma pack(1)

#pragma pack()