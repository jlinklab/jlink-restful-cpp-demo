/*
功能：获取设备回放地址请求体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=a3895a78305a4be88073ff6a9823c171&lang=zh
*/
#pragma once
#include "request/request.h"

class PlayBackAddressRequest
{
public:
    int channel;
    int streamType;
    std::string startTime;
    std::string endTime;
    std::string FileName;
    std::string protocol;
    int download;
    int playPrioritize;

    PlayBackAddressRequest()
        : channel(0)
        , streamType(0)
        , download(0)
        , playPrioritize(0)
    { }
};

namespace nlohmann
{
template <>
struct adl_serializer<PlayBackAddressRequest>
{
    static void to_json(json& j, const PlayBackAddressRequest& in)
    {
        j = json{
            {"channel", in.channel},
            {"streamType", in.streamType},
            {"startTime", in.startTime},
            {"endTime", in.endTime},
            {"FileName", in.FileName},
            {"protocol", in.protocol},
            {"download", in.download},
            {"playPrioritize", in.playPrioritize}
        };
    }
};
} // namespace nlohmann