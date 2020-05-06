#pragma once

enum LoginClientMsg
{
    CMD_LOGIN_C_LOGIN_TOKEN = 100,          //通过token登录
    CMD_LOGIN_C_FRIEND_MESSAGE = 101,       //好友消息
    CMD_LOGIN_C_GROUP_MESSAGE = 102,        //群消息
};

enum LoginServerMsg
{
    CMD_LOGIN_S_LOGIN_SUCCESS = 100,        //登录成功
    CMD_LOGIN_S_LOGIN_FAILD = 101,          //登录失败
    CMD_LOGIN_S_USER_STATUS = 102,          //用户状态变更
    CMD_LOGIN_S_FRIEND_LIST = 103,          //好友列表
    CMD_LOGIN_S_FRIEND_MESSAGE = 104,       //好友消息
    CMD_LOGIN_S_GROUP_MESSAGE = 105,        //群消息
    CMD_LOGIN_S_LOGIN_AFRESH = 106,         //顶号
};