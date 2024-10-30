/*
功能：获取云存报警视频列表请求体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=66142b2ca13c418d84085772a627d650&lang=zh
*/
#pragma once
#include "request/request.h"

class VideoInfoRequest
{
public:
    std::string startTime;
    std::string stopTime;
    std::string channel;
};

namespace nlohmann
{
template <>
struct adl_serializer<VideoInfoRequest>
{
    static void to_json(json& j, const VideoInfoRequest& in)
    {
        j = json{
            {"startTime", in.startTime},
            {"stopTime", in.stopTime},
            {"channel", in.channel},
        };
    }
};
} // namespace nlohmann