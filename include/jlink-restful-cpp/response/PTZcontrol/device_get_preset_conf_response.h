/*
功能：获取预置点配置响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=6f7d887c974444f4a18040fc2db07ae2&lang=zh
*/
#pragma once
#include "response/response.h"

class GetPTZPreSetConf
{
public:
    std::string name;
    int ret;
    std::string session_id;
};

namespace nlohmann
{
template <>
struct adl_serializer<GetPTZPreSetConf>
{
    static void from_json(const json& j, GetPTZPreSetConf& out)
    {
        out.name = j.value("Name", "");
        out.ret = j.value("Ret", 0);
        out.session_id = j.value("SessionID", "");
    }
};
} // namespace nlohmann
using DeviceGetPTZPreSetConfResponse = Response<GetPTZPreSetConf>;
