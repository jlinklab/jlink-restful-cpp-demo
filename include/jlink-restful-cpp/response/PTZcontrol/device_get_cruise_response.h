/*
功能：获取巡航路径配置响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=95e4a74f431a42ab855b167ac87372b2&lang=zh
*/
#pragma once
#include "response/response.h"

class GetCruise
{
public:
    std::string name;
    int ret;
    std::string session_id;
};

namespace nlohmann
{
template <>
struct adl_serializer<GetCruise>
{
    static void from_json(const json& j, GetCruise& out)
    {
        out.name = j.value("Name", "");
        out.ret = j.value("Ret", 0);
        out.session_id = j.value("SessionID", "");
    }
};
} // namespace nlohmann
using DeviceGetCruiseConfResponse = Response<GetCruise>;
