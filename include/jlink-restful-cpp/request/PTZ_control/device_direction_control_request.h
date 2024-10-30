/*
功能：云台方向控制请求体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=721897f552444cce9c380e34c3fed6f6&lang=zh
*/
#pragma once
#include "request/request.h"

class DirectionControlParams
{
public:
    std::string Preset; 
    std::string Channel;
    std::string Step;
};

class DirectionControlRequest
{
public:
    std::string Command;
    DirectionControlParams Parameter;
};

namespace nlohmann
{
template <>
struct adl_serializer<DirectionControlParams>
{
    static void to_json(json& j, const DirectionControlParams& in)
    {
        j = json{
            {"Preset", in.Preset},
            {"Channel", in.Channel},
            {"Step", in.Step}
        };
    }
};

template <>
struct adl_serializer<DirectionControlRequest>
{
    static void to_json(json& j, const DirectionControlRequest& in)
    {
        j = json{
            {"Command", in.Command},
            {"Parameter", in.Parameter}
        };
    }
};
} // namespace nlohmann