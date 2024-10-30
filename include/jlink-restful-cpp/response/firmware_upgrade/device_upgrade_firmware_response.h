/*
功能：开始升级固件响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=1175fc4e3160af8ec6f022e458f1f3b7&lang=zh
*/
#pragma once
#include "response/response.h"

class UpgradeFirmware
{
public:
    std::string name;
    int ret;
    std::string session_id;
};

namespace nlohmann
{
template <>
struct adl_serializer<UpgradeFirmware>
{
    static void from_json(const json& j, UpgradeFirmware& out)
    {
        out.name = j.value("Name", "");
        out.ret = j.value("Ret", 0);
        out.session_id = j.value("SessionID", "");
    }
};
} // namespace nlohmann
using DeviceUpgradeFirmwareResponse = Response<UpgradeFirmware>;