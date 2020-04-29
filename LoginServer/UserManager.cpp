#include "UserManager.h"

UserManager::UserManager(/* args */)
{
}

UserManager::~UserManager()
{
}
//查找用户
std::shared_ptr<UserServerItem> UserManager::searchUserByUserID(int userID)
{
    auto iter = idUsers_.find(userID);
    if(iter == idUsers_.end()) return nullptr;

    return iter->second;
}
std::shared_ptr<UserServerItem> UserManager::searchUserBySocketID(uint64_t socketID)
{
    auto iter = socketIDUsers_.find(socketID);
    if(iter == socketIDUsers_.end()) return nullptr;

    return iter->second;
}
std::shared_ptr<UserServerItem> UserManager::createUser(uint64_t socketID,const UserInfo& info)
{
    auto p = std::make_shared<UserServerItem>();
    p->socketID(socketID);
    p->userStatus(USER_STATUS_ONLINE);
    p->userInfo(info);

    idUsers_[info.userID] = p;
    socketIDUsers_[socketID] = p;

    return p;
}

//删除用户
void UserManager::removeUserByUserID(int userID)
{
    auto iter = idUsers_.find(userID);
    if(iter != idUsers_.end())
    {
        uint64_t socketID = iter->second->socketID();

        idUsers_.erase(iter);
        removeUserBySocketID(socketID);
    }
}
void UserManager::removeUserBySocketID(uint64_t socketID)
{
     auto iter = socketIDUsers_.find(socketID);
    if(iter != socketIDUsers_.end())
    {
        int userID = iter->second->userInfo().userID;

        socketIDUsers_.erase(iter);
        removeUserByUserID(userID);
    }
}