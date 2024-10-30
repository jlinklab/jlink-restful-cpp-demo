/*
功能：恢复出厂设置响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=1881639185144ebd995c2b2dbad40412&lang=zh
*/
#pragma once
#include "response/response.h"

class RestoreFactorySetting
{
public:
    std::string name;
    int ret;
    std::string session_id;
};

namespace nlohmann
{
template <>
struct adl_serializer<RestoreFactorySetting>
{
    static void from_json(const json& j, RestoreFactorySetting& out)
    {
        out.name = j.value("Name", "");
        out.ret = j.value("Ret", 0);
        out.session_id = j.value("SessionID", "0x00000000");
    }
};
} // namespace nlohmann

using DeviceRestoreFactorySettingResponse = Response<RestoreFactorySetting>;