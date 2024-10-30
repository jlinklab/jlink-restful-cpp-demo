/*
功能：(拒绝/接受)邀请用户加入家庭
描述：详见https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=abd718e5b25c4613ac977288731b4921&lang=zh
*/
#pragma once

#include <stdint.h>
#include <string>
#include <vector>
#include "message.h"

class PropValueInvite
{
public:
    std::string user_group_name; // 家庭组名称
    std::string user_group_id; // 家庭组id
    std::string nick_name; // 被邀请者用户昵称  
    std::string user_id; // 被邀请者/用户账号   
    std::string inviter_userId; // 邀请者用户账号
    std::string inviter_nickname; // 邀请者昵称
};

class PropInvite
{
public:
    std::string propCode;   // 属性编码
    PropValueInvite propValue;  // 属性值
};

class InviteMessageBodyMsg
{
public:
    int seq;                // 序列号
    std::vector<PropInvite> props; // 属性列表
};

namespace nlohmann
{
template<>
struct adl_serializer<PropValueInvite>
{
    static void from_json(const json& j, PropValueInvite& out)
    {
        out.user_group_name = j.value("userGroupName", "");
        out.user_group_id = j.value("userGroupId", "");
        out.nick_name = j.value("nickName", "");
        out.user_id = j.value("userId0", "");
        out.inviter_userId = j.value("inviterUserId", "");
        out.inviter_nickname = j.value("inviterNickName", "");
    }
};

template <>
struct adl_serializer<PropInvite>
{
    static void from_json(const json& j, PropInvite& out)
    {
        out.propCode = j.value("propCode", "");
        out.propValue = j.value("propValue", PropValueInvite());
    }
};

template <>
struct adl_serializer<InviteMessageBodyMsg>
{
    static void from_json(const json& j, InviteMessageBodyMsg& out)
    {
        out.seq = j.value("seq", 0);
        out.props = j.value("props", std::vector<PropInvite>());
    }
};
}