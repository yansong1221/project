#include "UserFriendManager.h"

UserFriendGroup::UserFriendGroup(int ownerUserID)
    : ownerUserID_(ownerUserID)
{
}
UserFriendGroup::~UserFriendGroup()
{
}
 //查找好友信息
std::shared_ptr<ServerFriendInfo> UserFriendGroup::searchUser(int userID)
{
    auto iter = friends_.find(userID);
    if(iter == friends_.end()) return nullptr;
    return iter->second;
}
//追加好友
bool UserFriendGroup::appendFriendInfo(const ServerFriendInfo &info)
{
    auto friendUser = searchUser(info.userID);
    if(friendUser != nullptr) return false;

    friendUser = std::make_shared<ServerFriendInfo>();
    friendUser->userID = info.userID;
    friendUser->sex = info.sex;
    friendUser->nickName = info.nickName;
    friendUser->headUrl = info.headUrl;
    friendUser->alias = info.alias;
    friendUser->messageIndex = info.messageIndex;

    friends_[info.userID] = friendUser;
    return true;
}
//移除好友
bool UserFriendGroup::removeFriendInfo(int userID)
{
     auto iter = friends_.find(userID);
    if(iter == friends_.end()) return false;
    friends_.erase(iter);

    return true;
}
//所属用户
int UserFriendGroup::ownerUserID() const
{
    return ownerUserID_;
}
//获取所有好友
std::vector<std::shared_ptr<ServerFriendInfo>> UserFriendGroup::allFriend()
{
    std::vector<std::shared_ptr<ServerFriendInfo>> ret;
    for(auto v : friends_)
    {
        ret.push_back(v.second);
    }
    return ret;
}

 UserFriendGroupManager::UserFriendGroupManager()
 {

 }
UserFriendGroupManager::~UserFriendGroupManager()
{

}
 //查找好友列表
std::shared_ptr<UserFriendGroup> UserFriendGroupManager::searchUserFriendGroup(int userID)
{
    auto iter = friendGroups_.find(userID);
    if(iter == friendGroups_.end()) return nullptr;
    return iter->second;
}
//创建好友列表
std::shared_ptr<UserFriendGroup> UserFriendGroupManager::createUserFriendGroup(int userID)
{
    auto friendGroup = searchUserFriendGroup(userID);
    if(friendGroup == nullptr)
    {
        friendGroup = std::make_shared<UserFriendGroup>(userID);
        friendGroups_[userID] = friendGroup;
    }
    return friendGroup;
}

//移除好友列表
void UserFriendGroupManager::removeUserFriendGroup(int userID)
{
    friendGroups_.erase(userID);
}

//更新消息index
long long UserFriendGroupManager::updateMessageIndex(int userID_1, int userID_2)
{
    long long messageIndex = 0;
    auto user1 = searchUserFriendGroup(userID_1);
    auto user2 = searchUserFriendGroup(userID_2);

    if(user1)
    {
        auto userinfo = user1->searchUser(userID_2);
        if(userinfo)
        {
            messageIndex = ++userinfo->messageIndex;
        }
    }

    if(user2)
    {
        auto userinfo = user2->searchUser(userID_1);
        if(userinfo)
        {
            messageIndex = ++userinfo->messageIndex;
        }
    }
    return messageIndex;
}