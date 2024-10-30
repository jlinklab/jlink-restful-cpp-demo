/*
功能：设备保活响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=89497855ae9e7ca46240d7e7b47dcdb7&lang=zh
*/
#pragma once
#include "response/response.h"

class DeviceAlive
{
public:
    std::string name;
    int ret;
};

namespace nlohmann
{
template <>
struct adl_serializer<DeviceAlive>
{
    static void from_json(const json& j, DeviceAlive& out)
    {
        out.name = j.value("Name", "");
        out.ret = j.value("123", 0);
    }
};
} // namespace nlohmann

using DeviceAliveResponse = Response<DeviceAlive>;