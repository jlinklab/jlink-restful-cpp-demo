/*
功能：同步UTC时间响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=4da974c55768c699ee6637415084c15e&lang=zh
*/
#pragma once
#include "response/response.h"

class SynUTC
{
public:
    std::string name;
    int ret;
    std::string session_id;
};

namespace nlohmann
{
template <>
struct adl_serializer<SynUTC>
{
    static void from_json(const json& j, SynUTC& out)
    {
        out.name = j.value("Name", "");
        out.ret = j.value("Ret", 0);
        out.session_id = j.value("SessionID", "");
    }
};
} // namespace nlohmann
using DeviceSynUTCResponse = Response<SynUTC>;