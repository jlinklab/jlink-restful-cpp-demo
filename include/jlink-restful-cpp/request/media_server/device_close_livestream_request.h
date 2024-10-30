/*
功能：关闭直播流请求体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=38ae09f37d874ea78bf517133a49b06a&lang=zh
*/
#pragma once
#include "request/request.h"

class CloseLiveStreamRequest
{
public:
    std::string channel;
    std::string stream;
};

namespace nlohmann
{
template <>
struct adl_serializer<CloseLiveStreamRequest>
{
    static void to_json(json& j, const CloseLiveStreamRequest& in)
    {
        j = json{
            {"channel", in.channel},
            {"stream", in.stream}
        };
    }
};
} // namespace nlohmann