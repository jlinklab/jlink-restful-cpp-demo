/*
功能：重启/关闭操作
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=06866833a28d4b629d9fa58d6fc0bc7b&lang=zh
*/
#pragma once
#include "request/request.h"

class RestartShutdownRequest
{
public:
    std::string action;
};

namespace nlohmann
{
template <>
struct adl_serializer<RestartShutdownRequest>
{
    static void to_json(json& j,const RestartShutdownRequest& in)
    {
        j = json{
            {"Action", in.action}
        };
    }
};
} // namespace nlohmann