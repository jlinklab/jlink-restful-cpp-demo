/*
功能：设备语音对讲请求体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=8ec4967ab4284e4ea30024fb259ef8be&lang=zh
*/
#pragma once
#include "request/request.h"

class TalkBackRequest
{
public:
    std::string mediaType;
    std::string channel;
    std::string protocol;
    std::string audioCode;
};

namespace nlohmann
{
template <>
struct adl_serializer<TalkBackRequest>
{
    static void to_json(json& j, const TalkBackRequest& in)
    {
        j = json{
            {"mediaType", in.mediaType},
            {"channel", in.channel},
            {"protocol", in.protocol},
            {"audioCode", in.audioCode},
        };
    }
};
} // namespace nlohmann