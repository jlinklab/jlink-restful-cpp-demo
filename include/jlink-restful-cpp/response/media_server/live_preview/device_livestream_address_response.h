/*
功能：获取设备直播地址响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=a557173005f1443a8279b83978e9f917&lang=zh
*/
#pragma once
#include "response/response.h"

class LiveStream
{
public:
    int ret;
    std::string url;
    std::string ret_msg;
};

namespace nlohmann
{
template<>
struct adl_serializer<LiveStream>
{
    static void from_json(const json&j, LiveStream& out)
    {
        out.ret = j.value("Ret", 0);
        out.url = j.value("url", "");
        out.ret_msg = j.value("RetMsg", "");
    }
};
}

using DeviceLiveStreamResponse = Response<LiveStream>;