#include "UserItem.h"

 UserServerItem::UserServerItem()
 {
     socketID_ = 0;
     userStatus_ = UserStatus::USER_STATUS_OFFLINE;
 }
UserServerItem::~UserServerItem()
{

}

 void UserServerItem::userInfo(const UserInfo& info)
 {
    userInfo_ = info;
 }
UserInfo& UserServerItem::userInfo()
{
    return userInfo_;
}

void UserServerItem::socketID(uint64_t id)
{
    socketID_ = id;
}
uint64_t UserServerItem::socketID() const
{
    return socketID_;
}
void UserServerItem::userStatus(UserStatus status)
{
    userStatus_ = status;
}
UserStatus UserServerItem::userStatus() const
{
    return userStatus_;
}