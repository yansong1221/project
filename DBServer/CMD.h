#pragma once

enum DBClientMsg
{
    CMD_DB_C_LOGIN_TOKEN = 100,                 //登录
    CMD_DB_C_LOAD_FRIEND_LIST,                  //加载好友列表
    CMD_DB_C_LOAD_GROUP_LIST,                   //加载群列表
    CMD_DB_C_SAVE_FRIEND_MESSAGE,               //保存好友消息
    CMD_DB_C_SAVE_GROUP_MESSAGE,                //保存群消息
};

enum DBServerMsg
{
    CMD_DB_S_LOGIN_RESULT = 100,                //登录结果
    CMD_DB_S_LOAD_FRIEND_LIST_RESULT,           //加载好友列表结果
    CMD_DB_S_LOAD_GROUP_LIST_RESULT,            //加载群组列表
};