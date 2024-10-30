/*
功能：删除家庭组
描述：详见https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=abd718e5b25c4613ac977288731b4921&lang=zh
*/
#pragma once

#include <stdint.h>
#include <string>
#include <vector>
#include "message.h"

class PropValueDelFamily
{
public:
    std::string user_group_name; // 家庭组名称
    std::string user_group_id; // 家庭组id
    std::string nick_name; // 用户昵称
    std::string user_id; // 删除者id     
};

class PropDelFamily
{
public:
    std::string propCode;   // 属性编码
    PropValueDelFamily propValue;  // 属性值
};

class DelFamilyMessageBodyMsg
{
public:
    int seq;                // 序列号
    std::vector<PropDelFamily> props; // 属性列表
};

namespace nlohmann
{
template<>
struct adl_serializer<PropValueDelFamily>
{
    static void from_json(const json& j, PropValueDelFamily& out)
    {
        out.user_group_name = j.value("userGroupName", "");
        out.user_group_id = j.value("userGroupId", "");
        out.nick_name = j.value("nickName", "");
        out.user_id = j.value("userId0", "");
    }
};

template <>
struct adl_serializer<PropDelFamily>
{
    static void from_json(const json& j, PropDelFamily& out)
    {
        out.propCode = j.value("propCode", "");
        out.propValue = j.value("propValue", PropValueDelFamily());
    }
};

template <>
struct adl_serializer<DelFamilyMessageBodyMsg>
{
    static void from_json(const json& j, DelFamilyMessageBodyMsg& out)
    {
        out.seq = j.value("seq", 0);
        out.props = j.value("props", std::vector<PropDelFamily>());
    }
};
}