/*
功能：查询设备日志响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=a48770f127ba4ee1a40cb20f010b8ed5&lang=zh
*/
#pragma once
#include "response/response.h"

using json = nlohmann::json;

class OPLog
{
public:
    std::string Data;
    int Position;
    std::string Time;
    std::string Type;
    std::string User;
};

class OPLogQueryResponse
{
public:
    std::string name;
    int ret;
    std::string session_id;
    std::vector<OPLog> OPLogQuery;
};

namespace nlohmann
{
template <>
struct adl_serializer<OPLog>
{
    static void from_json(const json& j, OPLog& out)
    {
        out.Data = j.value("Data", "");
        out.Position = j.value("Position", 0);
        out.Time = j.value("Time", "");
        out.Type = j.value("Type", "");
        out.User = j.value("User", "");
    }
};

template <>
struct adl_serializer<OPLogQueryResponse>
{
    static void from_json(const json& j, OPLogQueryResponse& out)
    {
        out.name = j.value("Name", "");
        out.ret = j.value("Ret", 0);
        out.session_id = j.value("SessionID", "");
        out.OPLogQuery = j.value("OPLogQuery", std::vector<OPLog>());
    }
};
} // namespace nlohmann

using DeviceOPLogQueryResponse = Response<OPLogQueryResponse>;
