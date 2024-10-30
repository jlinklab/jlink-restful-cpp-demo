/*
功能：根据时间点获取报警视频片段信息请求体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=512d81cbb4dc4012bb38f2d5c004fdec&lang=zh
*/
#pragma once
#include "request/request.h"

class VideoDetailRequest
{
public:
    std::string alarmTimes;
    std::string channel;
};

namespace nlohmann
{
template <>
struct adl_serializer<VideoDetailRequest>
{
    static void to_json(json& j, const VideoDetailRequest& in)
    {
        j = json{
            {"alarmTimes", in.alarmTimes},
            {"channel", in.channel}
        };
    }
};
} // namespace nlohmann