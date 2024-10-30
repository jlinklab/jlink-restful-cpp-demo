/*
功能：设备登录响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=66749545f6c3e2b0526182efaad416bb&lang=zh
*/
#pragma once
#include "response/response.h"

class DeviceLogin
{
public:
    int alive_interval;
    int chnnel_num;
    std::string device_type;
    int ret;
    std::string session_id;
};

namespace nlohmann
{
template <>
struct adl_serializer<DeviceLogin>
{
    static void from_json(const json& j, DeviceLogin& out)
    {
        // 解析各字段
        out.alive_interval = j.value("AliveInterval", 0);
        out.chnnel_num = j.value("ChannelNum", 0);
        out.device_type = j.value("DeviceType ", "");
        out.ret = j.value("Ret", 0);
        out.session_id = j.value("SessionID", "");
    }
};
} // namespace nlohmann

using DeviceLoginResponse = Response<DeviceLogin>;