#include "GroupManager.h"

Group::Group(uint64_t groupID, const std::string &name,long long messageIndex)
    : groupID_(groupID),
      groupName_(name),
      messageIndex_(messageIndex)
{
}
Group::~Group()
{
}
std::vector<std::shared_ptr<GroupMemberInfo>> Group::allMember()
{
    std::vector<std::shared_ptr<GroupMemberInfo>> ret;
    for (auto v : groupMembers_)
        ret.push_back(v.second);
    return ret;
}
//追加群
bool Group::appendMember(const GroupMemberInfo &info)
{
    if (searchMember(info.userID) != nullptr)
        return false;

    auto p = std::make_shared<GroupMemberInfo>();
    p->userID = info.userID;
    p->level = info.level;
    p->groupNickName = info.groupNickName;

    groupMembers_[info.userID] = p;
    return true;
}
//移除群
bool Group::removeMember(uint64_t userID)
{
    groupMembers_.erase(userID);
    return true;
}
//所属
uint64_t Group::groupID() const
{
    return groupID_;
}
//查找群
std::shared_ptr<GroupMemberInfo> Group::searchMember(int userID)
{
    auto iter = groupMembers_.find(userID);
    if (iter != groupMembers_.end())
        return iter->second;
    return nullptr;
}
long long Group::updateMessageIndex()
{
    return ++messageIndex_;
}
//群名字
std::string Group::groupName() const
{
    return groupName_;
}

GroupManager::GroupManager()
{
}
GroupManager::~GroupManager()
{
}

//查找用户的群列表
std::shared_ptr<Group> GroupManager::searchGroup(uint64_t groupID)
{
    auto iter = groups_.find(groupID);
    if (iter != groups_.end())
        return iter->second;
    return nullptr;
}
//创建群列表
std::shared_ptr<Group> GroupManager::createGroup(uint64_t groupID, const std::string &groupName,long long messageIndex)
{
    auto p = searchGroup(groupID);
    if (p == nullptr)
    {
        p = std::make_shared<Group>(groupID, groupName,messageIndex);
    }
    return p;
}
//移除群列表
void GroupManager::removeGroup(uint64_t groupID)
{
    groups_.erase(groupID);
}
std::vector<std::shared_ptr<Group>> GroupManager::searchUserGroup(int userID)
{
    std::vector<std::shared_ptr<Group>> ret;

    for (auto v : groups_)
    {
        auto member = v.second->searchMember(userID);
        if (member == nullptr)
            continue;
        ret.push_back(v.second);
    }
    return ret;
}
void GroupManager::clear()
{
    groups_.clear();
}