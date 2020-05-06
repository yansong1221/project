#pragma once
#include <cstdint>
#include <memory>
#include <string>
#include <map>
#include <vector>

struct GroupMemberInfo
{
    int userID;
    std::string groupNickName;
    int level; //群主标记，0普通成员1副群主,2群主
};

class Group
{
public:
    Group(uint64_t groupID,const std::string& name,long long messageIndex);
    ~Group();

public:
    //追加成员
    bool appendMember(const GroupMemberInfo &info);
    //移除成员
    bool removeMember(uint64_t userID);
    //所属
    uint64_t groupID() const;
    //群名字
    std::string groupName() const;
    //查找成员
    std::shared_ptr<GroupMemberInfo> searchMember(int userID);
    //获取群的所有成员
    std::vector<std::shared_ptr<GroupMemberInfo>> allMember();

    long long updateMessageIndex();
private:
    std::map<int,std::shared_ptr<GroupMemberInfo>> groupMembers_;
    uint64_t groupID_;
    std::string groupName_;
    long long messageIndex_;
};

class GroupManager
{
public:
    GroupManager();
    ~GroupManager();

public:
    //查找用户的群列表
    std::shared_ptr<Group> searchGroup(uint64_t groupID);
    //创建群列表
    std::shared_ptr<Group> createGroup(uint64_t groupID,const std::string& groupName,long long messageIndex);
    //移除群列表
    void removeGroup(uint64_t groupID);
    //查找用户所有的群
    std::vector<std::shared_ptr<Group>> searchUserGroup(int userID);
    //清空
    void clear();
private:
    std::map<uint64_t, std::shared_ptr<Group>> groups_;
};