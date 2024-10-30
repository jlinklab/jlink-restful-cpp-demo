/*
功能：清空设备日志响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=5a84b5d87f754bec82d63fb40ead52f9&lang=zh
*/
#pragma once
#include "response/response.h"

class ClearLog
{
public:
    std::string name;
    int ret;
    std::string session_id;
};

namespace nlohmann
{
template <>
struct adl_serializer<ClearLog>
{
    static void from_json(const json& j, ClearLog& out)
    {
        out.name = j.value("Name", "");
        out.ret = j.value("Ret", 0);
        out.session_id = j.value("SessionID", "0x00000000");
    }
};
} // namespace nlohmann

using DeviceClearLogResponse = Response<ClearLog>;