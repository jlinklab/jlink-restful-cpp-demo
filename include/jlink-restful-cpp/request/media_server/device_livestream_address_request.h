/*
功能：获取设备直播地址请求体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=a557173005f1443a8279b83978e9f917&lang=zh
*/
#pragma once
#include "request/request.h"

class LiveStreamRequest
{
public:
    std::string mediaType;
    std::string channel;
    std::string stream;
    std::string protocol;
    std::string username;
    std::string password;
    std::string videoCode;
    std::string audioCode;
    std::string expireTime;
};

namespace nlohmann
{
template <>
struct adl_serializer<LiveStreamRequest>
{
    static void to_json(json& j, const LiveStreamRequest& in)
    {
        j = json{
            {"mediaType", in.mediaType},
            {"channel", in.channel},
            {"stream", in.stream},
            {"protocol", in.protocol},
            {"username", in.username},
            {"password", in.password},
            {"audioCode", in.audioCode},
            {"expireTime", in.expireTime}
        };
    }
};
} // namespace nlohmann