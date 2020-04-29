#pragma once

#include "UserItem.h"
#include <map>
#include <memory>
class UserManager
{
private:
    /* data */
public:
    UserManager(/* args */);
    ~UserManager();

public:
    
    //查找用户
    std::shared_ptr<UserServerItem> searchUserByUserID(int userID);
    std::shared_ptr<UserServerItem> searchUserBySocketID(uint64_t socketID);

    //创建用户
     std::shared_ptr<UserServerItem> createUser(uint64_t socketID,const UserInfo& info);

     //删除用户
     void removeUserByUserID(int userID);
     void removeUserBySocketID(uint64_t socketID);

private:
    std::map<int,std::shared_ptr<UserServerItem>> idUsers_;
    std::map<uint64_t,std::shared_ptr<UserServerItem>> socketIDUsers_;
};


