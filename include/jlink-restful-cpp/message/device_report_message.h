/*
功能：设备上报
描述：详见https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=abd718e5b25c4613ac977288731b4921&lang=zh
*/
#pragma once

#include <stdint.h>
#include <string>
#include <vector>
#include "message.h"

class Prop
{
public:
    std::string propCode;   // 属性编码
    std::string propValue;  // 属性值
};

class MessageBodyMsg
{
public:
    int seq;                // 序列号
    std::vector<Prop> props; // 属性列表
};

namespace nlohmann
{
template <>
struct adl_serializer<Prop>
{
    static void from_json(const json& j, Prop& out)
    {
        out.propCode = j.value("propCode", "");
        out.propValue = j.value("propValue", "");
    }
};

template <>
struct adl_serializer<MessageBodyMsg>
{
    static void from_json(const json& j, MessageBodyMsg& out)
    {
        out.seq = j.value("seq", 0);
        out.props = j.value("props", std::vector<Prop>());
    }
};
}