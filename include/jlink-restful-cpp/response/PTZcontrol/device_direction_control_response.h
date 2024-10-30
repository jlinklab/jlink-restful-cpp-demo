/*
功能：方向控制响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=721897f552444cce9c380e34c3fed6f6&lang=zh
*/
#pragma once
#include "response/response.h"

class DirectionControl
{
public:
    std::string name;
    int ret;
    std::string session_id;
};

namespace nlohmann
{
template <>
struct adl_serializer<DirectionControl>
{
    static void from_json(const json& j, DirectionControl& out)
    {
        out.name = j.value("Name", "");
        out.ret = j.value("Ret", 0);
        out.session_id = j.value("SessionID", "");
    }
};
} // namespace nlohmann
using DeviceDirectionControlResponse = Response<DirectionControl>;