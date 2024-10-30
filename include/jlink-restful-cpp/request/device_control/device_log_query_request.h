/*
功能：查询设备日志请求体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=a48770f127ba4ee1a40cb20f010b8ed5&lang=zh
*/
#pragma once
#include "request/request.h"

class LogQueryRequest
{
public:
    std::string Type;
    int LogPosition;
    std::string BeginTime;
    std::string EndTime;
};

namespace nlohmann
{
template <>
struct adl_serializer<LogQueryRequest>
{
    static void to_json(json& j, const LogQueryRequest& in)
    {
        j = json{
            {"Type", in.Type},
            {"LogPosition", in.LogPosition},
            {"BeginTime", in.BeginTime},
            {"EndTime", in.EndTime}
        };
    }
};
} // namespace nlohmann