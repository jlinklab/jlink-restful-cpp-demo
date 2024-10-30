/*
功能：设置通用配置响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=270aca4b56504d088dc0dc9156e370ff&lang=zh
*/
#pragma once
#include "response/response.h"

class SetGeneral
{
public:
    std::string name;
    int ret;
    std::string session_id;
};

namespace nlohmann
{
template <>
struct adl_serializer<SetGeneral>
{
    static void from_json(const json& j, SetGeneral& out)
    {
        out.name = j.value("Name", "");
        out.ret = j.value("Ret", 0);
        out.session_id = j.value("SessionID", "");
    }
};
} // namespace nlohmann
using DeviceSetGeneralConfResponse = Response<SetGeneral>;