/*
功能：删除设备分享
描述：详见https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=abd718e5b25c4613ac977288731b4921&lang=zh
*/
#pragma once

#include <stdint.h>
#include <string>
#include <vector>
#include "message.h"

class PropValueDelShare
{
public:
    std::string nick_name; // 操作者昵称
    std::string device_name; //设备名称
    std::string user_id; // 删除者id
};

class PropDelShare
{
public:
    std::string propCode;   // 属性编码
    PropValueDelShare propValue;  // 属性值
};

class DelShareMessageBodyMsg
{
public:
    int seq;                // 序列号
    std::vector<PropDelShare> props; // 属性列表
};

namespace nlohmann
{
template<>
struct adl_serializer<PropValueDelShare>
{
    static void from_json(const json& j, PropValueDelShare& out)
    {
        out.nick_name = j.value("nickName", "");
        out.user_id = j.value("userId0", "");
        out.device_name = j.value("deviceName", "");
    }
};

template <>
struct adl_serializer<PropDelShare>
{
    static void from_json(const json& j, PropDelShare& out)
    {
        out.propCode = j.value("propCode", "");
        out.propValue = j.value("propValue", PropValueDelShare());
    }
};

template <>
struct adl_serializer<DelShareMessageBodyMsg>
{
    static void from_json(const json& j, DelShareMessageBodyMsg& out)
    {
        out.seq = j.value("seq", 0);
        out.props = j.value("props", std::vector<PropDelShare>());
    }
};
}