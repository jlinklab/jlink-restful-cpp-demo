/*
功能：删除用户
描述：详见https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=abd718e5b25c4613ac977288731b4921&lang=zh
*/
#pragma once

#include <stdint.h>
#include <string>
#include <vector>
#include "message.h"

class PropValueDelUser
{
public:
    std::string user_group_name; // 家庭组名称
    std::string user_group_id; // 家庭组id
    std::string nick_name; // 被删除者用户昵称
    bool self_del; // 是否是自己删除
    std::string user_id; // 被删除者用户账号     
    std::string del_by_userid; // 删除者账号
};

class PropDelUser
{
public:
    std::string propCode;   // 属性编码
    PropValueDelUser propValue;  // 属性值
};

class DelUserMessageBodyMsg
{
public:
    int seq;                // 序列号
    std::vector<PropDelUser> props; // 属性列表
};

namespace nlohmann
{
template<>
struct adl_serializer<PropValueDelUser>
{
    static void from_json(const json& j, PropValueDelUser& out)
    {
        out.user_group_name = j.value("userGroupName", "");
        out.user_group_id = j.value("userGroupId", "");
        out.nick_name = j.value("nickName", "");
        out.user_id = j.value("userId0", "");
    }
};

template <>
struct adl_serializer<PropDelUser>
{
    static void from_json(const json& j, PropDelUser& out)
    {
        out.propCode = j.value("propCode", "");
        out.propValue = j.value("propValue", PropValueDelUser());
    }
};

template <>
struct adl_serializer<DelUserMessageBodyMsg>
{
    static void from_json(const json& j, DelUserMessageBodyMsg& out)
    {
        out.seq = j.value("seq", 0);
        out.props = j.value("props", std::vector<PropDelUser>());
    }
};
}