/*
功能：获取设备回放地址响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=a3895a78305a4be88073ff6a9823c171&lang=zh
*/
#pragma once
#include "response/response.h"

class PlayBackAddress
{
public:
    int ret;
    std::string url;
};

namespace nlohmann
{
template<>
struct adl_serializer<PlayBackAddress>
{
    static void from_json(const json&j, PlayBackAddress& out)
    {
        out.ret = j.value("Ret", 0);
        out.url = j.value("url", "");
    }
};
}

using DevicePlayBackAddressResponse = Response<PlayBackAddress>;