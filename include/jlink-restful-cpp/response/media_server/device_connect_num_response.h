/*
功能：获取设备媒体流客户端连接数响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=22e2a0196a944a6f8b2e87ef29922db7&lang=zh
*/
#pragma once
#include "response/response.h"

class Info
{
public:
    int channel;
    int stream;
    int hls;
    int flv;
    int rtmp;
    int rtsp;
    int sum;
};

class StreamInfoResponse
{
public:
    int sum;
    std::vector<Info> info;
};

namespace nlohmann
{
template <>
struct adl_serializer<Info>
{
    static void from_json(const json& j, Info& out)
    {
        out.channel = j.value("channel", 0);
        out.stream = j.value("stream", 0);
        out.hls = j.value("hls", 0);
        out.flv = j.value("flv", 0);
        out.rtmp = j.value("rtmp", 0);
        out.rtsp = j.value("rtsp", 0);
        out.sum = j.value("sum", 0);
    }
};

template <>
struct adl_serializer<StreamInfoResponse>
{
    static void from_json(const json& j, StreamInfoResponse& out)
    {
        out.sum = j.value("sum", 0);
        out.info = j.value("info", std::vector<Info>());
    }
};
}

using DeviceConnectNumResponse = Response<StreamInfoResponse>;