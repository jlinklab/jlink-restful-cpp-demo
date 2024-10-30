/*
功能：系统时间查询响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=75ad94a2a63c448ba8a7b8fe46b16b57&lang=zh
*/
#pragma once
#include "response/response.h"

class SystemTime
{
public:
    std::string name;
    int ret;
    std::string session_id;
};

namespace nlohmann
{
template <>
struct adl_serializer<SystemTime>
{
    static void from_json(const json& j, SystemTime& out)
    {
        out.name = j.value("Name", "");
        out.ret = j.value("Ret", 0);
        out.session_id = j.value("SessionID", "0x00000000");
    }
};
} // namespace nlohmann

using DeviceSystemTimeResponse = Response<SystemTime>;