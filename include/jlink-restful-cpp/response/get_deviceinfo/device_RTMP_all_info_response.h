/*
功能：获取NVR全通道RTMP信息响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=65c07cc4b3ba4fe481c2d238e094aff1&lang=zh
*/
#pragma once
#include "response/response.h"

class RTMPALLInfo
{
public:
    bool enable;
    std::string host;
    std::string node;
    int port;
    int streamType;
    std::string token;
};

class RTMPALLInfoResponse
{
public:
    std::string name;
    int ret;
    std::string session_id;
    std::vector<RTMPALLInfo> rtmp_all_info;
};

namespace nlohmann
{
template <>
struct adl_serializer<RTMPALLInfo>
{
    static void from_json(const json& j, RTMPALLInfo& out)
    {
        out.enable = j.value("Enable", false);
        out.host = j.value("Host", "");
        out.node = j.value("Node", "");
        out.port = j.value("Port", 0);
        out.streamType = j.value("StreamType", 0);
        out.token = j.value("Token", "");
    }
};

template<>
struct adl_serializer<RTMPALLInfoResponse>
{
    static void from_json(const json& j, RTMPALLInfoResponse& out)
    {
        out.name = j.value("Name", "");
        out.ret = j.value("Ret",  0);
        out.session_id = j.value("SesionID", "");
        out.rtmp_all_info = j.value("NetWork.RTMPALL", std::vector<RTMPALLInfo>());
    }
};
} // namespace nlohmann

using DeviceRTMPALLInfoRespone = Response<RTMPALLInfoResponse>;