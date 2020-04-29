#pragma once

enum LoginClientMsg
{
    CMD_LOGIN_C_LOGIN_TOKEN = 100,        //通过token登录
};

enum LoginServerMsg
{
    CMD_LOGIN_S_LOGIN_SUCCESS = 100,        //登录成功
    CMD_LOGIN_S_LOGIN_FAILD = 101,          //登录失败
};