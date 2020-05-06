#pragma once
#include <string>
#include <cstdint>
#include <memory>
enum UserStatus
{
    USER_STATUS_OFFLINE = 0,    //离线
    USER_STATUS_ONLINE,         //在线
    USER_STATUS_LEAVE,          //离开
    USER_STATUS_BUSY,           //繁忙
    USER_STATUS_UNDISTRUB,      //勿扰
    USER_STATUS_CORBET          //隐身
};

struct UserInfo
{
    int userID; //用户ID
    std::string nickName;
    int sex;
    std::string headUrl;

    UserInfo()
    {
        userID = 0;
        sex = 0;
    }
};

class UserServerItem : public std::enable_shared_from_this<UserServerItem>
{
public:
    UserServerItem();
    ~UserServerItem();

public:
    //用户信息
    void userInfo(const UserInfo& info);
    UserInfo& userInfo();

    //SocketID
    void socketID(uint32_t id);
    uint32_t socketID() const;

    //状态
    void userStatus(UserStatus status);
    UserStatus userStatus() const;

private:
    
    //用户基本信息
    UserInfo userInfo_;

    uint32_t socketID_;
    UserStatus userStatus_;
};