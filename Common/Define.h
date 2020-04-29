#pragma once

#include <string>

#define	DEFAULT_BACKLOG_MAX					1024
//���ķ������˿�
#define DEFAULT_CENTER_PORT					8100


//�ڲ���Ϣ
static const uint32_t INTERNAL_MESSAGE_START = 10;


#define CALL_BACK_1(FUNC) std::bind(FUNC,this,std::placeholders::_1)
#define CALL_BACK_2(FUNC) std::bind(FUNC,this,std::placeholders::_1,std::placeholders::_2)
#define CALL_BACK_3(FUNC) std::bind(FUNC,this,std::placeholders::_1,std::placeholders::_2,std::placeholders::_3)