/*
功能：设置云台配置响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=e6885d066b3f48d1bf80350df7c051b5&lang=zh
*/
#pragma once
#include "response/response.h"

class SetPTZ
{
public:
    std::string name;
    int ret;
    std::string sessionID;
};

namespace nlohmann
{
template <>
struct adl_serializer<SetPTZ>
{
    static void from_json(const json& j, SetPTZ& out)
    {
        out.name = j.value("Name", "");
        out.ret = j.value("Ret", 0);
        out.sessionID = j.value("SessionID", "");
    }
};
} // namespace nlohmann
using DeviceSetExternalPTZConfResponse = Response<SetPTZ>;