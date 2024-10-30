/*
功能：云台变倍和聚焦控制请求体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=80410280fabf42d194a8efef97773424&lang=zh
*/
#pragma once
#include "request/request.h"

class ZoomFocusParams
{
public:
    std::string Channel;
    int step;
};

class ZoomFocusRequest
{
public:
    std::string Command;
    ZoomFocusParams Parameter;
};

namespace nlohmann
{
template <>
struct adl_serializer<ZoomFocusParams>
{
    static void to_json(json& j, const ZoomFocusParams& in)
    {
        j = json{
            {"Channel", in.Channel},
            {"step", in.step}
        };
    }
};

template <>
struct adl_serializer<ZoomFocusRequest>
{
    static void to_json(json& j, const ZoomFocusRequest& in)
    {
        j = json{
            {"Command", in.Command},
            {"Parameter", in.Parameter}
        };
    }
};
} // namespace nlohmann