/*
功能：设备视频对讲请求体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=dacf4fca875d410a9beeb4186cd5d8ce&lang=zh
*/
#pragma once
#include "request/request.h"

class VideoTalkRequest
{
public:
    std::string channel;
    std::string mediaType;
    std::string audioCodePlayer;
    std::string audioAccuracyPlayer;
    std::string videoPlayer;
    std::string widthPlayer;
    std::string heightPlayer;
    std::string fpsPlayer;
    std::string audioKHZPlayer;
};

namespace nlohmann
{
template <>
struct adl_serializer<VideoTalkRequest>
{
    static void to_json(json& j, const VideoTalkRequest& in)
    {
        j = json{
            {"channel", in.channel},
            {"stream", in.mediaType},
            {"audioCodePlayer", in.audioCodePlayer},
            {"audioAccuracyPlayer", in.audioAccuracyPlayer},
            {"videoPlayer", in.videoPlayer},
            {"widthPlayer", in.widthPlayer},
            {"heightPlayer", in.heightPlayer},
            {"fpsPlayer", in.fpsPlayer},
            {"audioKHZPlayer", in.audioKHZPlayer}
        };
    }
};
} // namespace nlohmann