/*
功能：云台点间巡航请求体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=1b55a40ea8254f7f8d915eac492ea797&lang=zh
*/
#pragma once
#include "request/request.h"

class PointCruiseParams
{
public:
    std::string Preset;
    std::string Channel;
    std::string Step;
    std::string Tour;
};

class PointCruiseRequest
{
public:
    std::string Command;
    PointCruiseParams Parameter;
};

namespace nlohmann
{
template <>
struct adl_serializer<PointCruiseParams>
{
    static void to_json(json& j, const PointCruiseParams& in)
    {
        j = json{
            {"Preset", in.Preset},
            {"Channel", in.Channel},
            {"Step", in.Step},
            {"Tour", in.Tour}
        };
    }
};

template <>
struct adl_serializer<PointCruiseRequest>
{
    static void to_json(json& j, const PointCruiseRequest& in)
    {
        j = json{
            {"Command", in.Command},
            {"Parameter", in.Parameter}
        };
    }
};
} // namespace nlohmann