/*
功能：点间巡航响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=1b55a40ea8254f7f8d915eac492ea797&lang=zh
*/
#pragma once
#include "response/response.h"

class PointCruise
{
public:
    std::string name;
    int ret;
    std::string session_id;
};

namespace nlohmann
{
template <>
struct adl_serializer<PointCruise>
{
    static void from_json(const json& j, PointCruise& out)
    {
        out.name = j.value("Name", "");
        out.ret = j.value("Ret", 0);
        out.session_id = j.value("SessionID", "");
    }
};
} // namespace nlohmann
using DevicePointCruiseResponse = Response<PointCruise>;
