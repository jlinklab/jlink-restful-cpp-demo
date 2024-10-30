/*
功能：设备登出响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=f1bd9969d70407747124f96728af4c08&lang=zh
*/
#pragma once
#include "response/response.h"

class DevLogout
{
public:
    int ret;
};

namespace nlohmann
{
template<>
struct adl_serializer<DevLogout>
{
    static void from_json(const json& j, DevLogout& out)
    {
        out.ret = j.value("Ret", 0);
    }
};
}

using DeviceLogoutResponse = Response<DevLogout>;