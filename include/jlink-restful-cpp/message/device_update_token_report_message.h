/*
功能：更新token	
描述：详见https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=abd718e5b25c4613ac977288731b4921&lang=zh
*/
#pragma once

#include <stdint.h>
#include <string>
#include <vector>
#include "message.h"

class PropValueUpdateToken
{
public:
    std::string admin_token; // adminToken
    std::string blueToken; // 蓝牙token
};

class PropUpdateToken
{
public:
    std::string propCode;   // 属性编码
    PropValueUpdateToken propValue;  // 属性值
};

class UpdateTokenMessageBodyMsg
{
public:
    int seq;                // 序列号
    std::vector<PropUpdateToken> props; // 属性列表
};

namespace nlohmann
{
template<>
struct adl_serializer<PropValueUpdateToken>
{
    static void from_json(const json& j, PropValueUpdateToken& out)
    {
        out.admin_token = j.value("adminToken", "");
        out.blueToken = j.value("bleToken", "");
    }
};

template <>
struct adl_serializer<PropUpdateToken>
{
    static void from_json(const json& j, PropUpdateToken& out)
    {
        out.propCode = j.value("propCode", "");
        out.propValue = j.value("propValue", PropValueUpdateToken());
    }
};

template <>
struct adl_serializer<UpdateTokenMessageBodyMsg>
{
    static void from_json(const json& j, UpdateTokenMessageBodyMsg& out)
    {
        out.seq = j.value("seq", 0);
        out.props = j.value("props", std::vector<PropUpdateToken>());
    }
};
}