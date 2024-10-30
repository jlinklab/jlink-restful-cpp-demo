/*
功能：获取设备通道配置响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=ebbd25ca797343b4bf984abf4bbc13ae&lang=zh
*/
#pragma once 
#include "response/response.h"

class ChannelTitle
{
public:
    std::vector<std::string> channel_title;
    std::string name;
    int ret;
    std::string sessionID;
};

namespace nlohmann
{
template<>
struct adl_serializer<ChannelTitle>
{
    static void from_json(const json& j, ChannelTitle& out)
    {
        out.channel_title = j.value("ChannelTitle", std::vector<std::string>()),
        out.name = j.value("Name", "");
        out.ret = j.value("Ret", 0);
        out.sessionID = j.value("SessionID", "");
    }
};
}
using DeviceChnnelTitleConfResponse = Response<ChannelTitle>;