/*
功能：重启/关闭操作响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=06866833a28d4b629d9fa58d6fc0bc7b&lang=zh
*/
#pragma once
#include "response/response.h"

class RestartShutdown
{
public:
    std::string name;
    int ret;
    std::string session_id;
};

namespace nlohmann
{
template <>
struct adl_serializer<RestartShutdown>
{
    static void from_json(const json& j, RestartShutdown& out)
    {
        out.name = j.value("Name", "");
        out.ret = j.value("Ret", 0);
        out.session_id = j.value("SessionID", "");
    }
};
} // namespace nlohmann
using DeviceRestartShutdownResponse = Response<RestartShutdown>;