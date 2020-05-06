#pragma once
#include <string>
#include <map>
#include <memory>
#include <vector>

struct ServerFriendInfo
{
    int userID;
    std::string nickName;
    int sex;
    std::string headUrl;
    std::string alias;
    long long messageIndex;
};

class UserFriendGroup
{
public:
    UserFriendGroup(int ownerUserID);
    ~UserFriendGroup();

public:
    //查找好友信息
    std::shared_ptr<ServerFriendInfo> searchUser(int userID); 
    //追加好友
    bool appendFriendInfo(const ServerFriendInfo &info);
    //移除好友
    bool removeFriendInfo(int userID);
    //所属用户
    int ownerUserID() const;
    //获取所有好友
    std::vector<std::shared_ptr<ServerFriendInfo>> allFriend();
private:
    std::map<int, std::shared_ptr<ServerFriendInfo>> friends_;

    int ownerUserID_; //所属的用户ID
};


class UserFriendGroupManager
{
public:
    UserFriendGroupManager();
    ~UserFriendGroupManager();
public:
    //查找好友列表
    std::shared_ptr<UserFriendGroup> searchUserFriendGroup(int userID);
    //创建好友列表
    std::shared_ptr<UserFriendGroup> createUserFriendGroup(int userID);
    //移除好友列表
    void removeUserFriendGroup(int userID);
    //更新消息index
    long long updateMessageIndex(int userID_1, int userID_2);
private:
    std::map<int,std::shared_ptr<UserFriendGroup>> friendGroups_;
};