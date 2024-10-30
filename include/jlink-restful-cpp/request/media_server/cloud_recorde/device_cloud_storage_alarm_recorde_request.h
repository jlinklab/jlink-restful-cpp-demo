/*
功能：获取云存报警视频回放地址请求体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=2e08468f46564602d01ae8a244661672&lang=zh
*/
#pragma once
#include "request/request.h"

class AlarmRecordeRequest
{
public:
    std::string startTime;
    std::string stopTime;
    std::string channel;
    std::string fileFormat;
};

namespace nlohmann
{
template <>
struct adl_serializer<AlarmRecordeRequest>
{
    static void to_json(json& j, const AlarmRecordeRequest& in)
    {
        j = json{
            {"startTime", in.startTime},
            {"stopTime", in.stopTime},
            {"channel", in.channel},
            {"fileFormat", in.fileFormat}
        };
    }
};
} // namespace nlohmann