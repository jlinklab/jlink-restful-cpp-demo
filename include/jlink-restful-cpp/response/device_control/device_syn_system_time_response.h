/*
功能：同步系统时间响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=a39c8602ae7e488e9ad2048ca10df1fe&lang=zh
*/
#pragma once
#include "response/response.h"

class SynSystemTime
{
public:
    std::string name;
    int ret;
    std::string session_id;
};

namespace nlohmann
{
template <>
struct adl_serializer<SynSystemTime>
{
    static void from_json(const json& j, SynSystemTime& out)
    {
        out.name = j.value("Name", "");
        out.ret = j.value("Ret", 0);
        out.session_id = j.value("SessionID", "0x00000000");
    }
};
} // namespace nlohmann

using DeviceSynSystemTimeResponse = Response<SynSystemTime>;