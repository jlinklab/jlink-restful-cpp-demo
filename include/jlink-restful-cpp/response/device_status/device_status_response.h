/*
功能：获取设备状态响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=beabe2df1298c15300b390b9213991c5&lang=zh
*/
#pragma once
#include "response/response.h"

class DeviceChannel
{
public:
    int main;
    int extra;
};

class DeviceStatus
{
public:
    std::string uuid;
    std::string status;
    std::list<DeviceChannel> channel;
};

namespace nlohmann
{
template <>
struct adl_serializer<DeviceChannel>
{
    static void from_json(const json& j, DeviceChannel& out)
    {
        out.main = j.value("main", 0);
        out.extra = j.value("extra", 0);
    }
};

template<>
struct adl_serializer<DeviceStatus>
{
    static void from_json(const json& j, DeviceStatus& out)
    {
        out.uuid = j.value("uuid", "");
        out.status = j.value("status", "");
        out.channel = j.value("channel", std::list<DeviceChannel>());
    }
};
} // namespace nlohmann

using DeviceStatusResponse = Response<DeviceStatus>;