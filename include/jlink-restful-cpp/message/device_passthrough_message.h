/*
功能：透传消息通知
描述：详见https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=51f722e2cf874140a4351d7400b09edb&lang=zh
*/
#pragma once

#include <stdint.h>
#include <string>
#include <vector>
#include "message.h"

class PassThroughMsg
{
public:
    std::string ms;
    std::string pid;
    std::string prop_code;
    std::string prop_value; // 设备上报的原始数据
};

namespace nlohmann
{
template <>
struct adl_serializer<PassThroughMsg>
{
    static void from_json(const json& j, PassThroughMsg& out)
    {
        out.ms = j.value("ms", 0);
        out.pid = j.value("pid", "");
        out.prop_code = j.value("propCode", "");
        out.prop_value = j.value("propValue", "");
    }
};
}