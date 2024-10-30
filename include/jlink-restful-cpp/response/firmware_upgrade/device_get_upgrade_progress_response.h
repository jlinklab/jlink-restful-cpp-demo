/*
功能：获取固件升级进度响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=7256501495311df288550c93c8c71b19&lang=zh
*/
#pragma once
#include "response/response.h"

class UpgradeProgress
{
public:
    std::string name;
    int ret;
    std::string session_id;
};

namespace nlohmann
{
template <>
struct adl_serializer<UpgradeProgress>
{
    static void from_json(const json& j, UpgradeProgress& out)
    {
        out.name = j.value("Name", "");
        out.ret = j.value("Ret", 0);
        out.session_id = j.value("SessionID", "");
    }
};
} // namespace nlohmann
using DeviceUpgradeProgressResponse = Response<UpgradeProgress>;

