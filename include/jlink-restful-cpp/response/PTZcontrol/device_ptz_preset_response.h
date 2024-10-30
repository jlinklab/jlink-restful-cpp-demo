/*
功能：预置点功能响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=50b75d2e72374ba8b2252beeb751634b&lang=zh
*/
#pragma once
#include "response/response.h"

class PTZPreSet
{
public:
    std::string name;
    int ret;
    std::string session_id;
};

namespace nlohmann
{
template <>
struct adl_serializer<PTZPreSet>
{
    static void from_json(const json& j, PTZPreSet& out)
    {
        out.name = j.value("Name", "");
        out.ret = j.value("Ret", 0);
        out.session_id = j.value("SessionID", "");
    }
};
} // namespace nlohmann
using DevicePTZPreSetResponse = Response<PTZPreSet>;
