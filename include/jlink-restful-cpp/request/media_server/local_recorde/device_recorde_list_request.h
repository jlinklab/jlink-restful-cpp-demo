/*
功能：获取回放列表请求体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=4b1516da5763439a9bc7175d7ac7d246&lang=zh
*/
#pragma once
#include "request/request.h"

class OPFileRequest
{
public:
    std::string BeginTime;
    std::string EndTime;
    int Channel;
    std::string DriverTypeMask;
    std::string Event;
    std::string StreamType;
    std::string Type;

    OPFileRequest() : Channel(0) { }
};

namespace nlohmann
{
template <>
struct adl_serializer<OPFileRequest>
{
    static void to_json(json& j, const OPFileRequest& in)
    {
        j = json{
            {"BeginTime", in.BeginTime},
            {"EndTime", in.EndTime},
            {"Channel", in.Channel},
            {"DriverTypeMask", in.DriverTypeMask},
            {"Event", in.Event},
            {"StreamType", in.StreamType},
            {"Type", in.Type}
        };
    }
};
} // namespace nlohmann