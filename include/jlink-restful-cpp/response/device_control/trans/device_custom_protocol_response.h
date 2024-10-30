/*
功能：自定义协议透传响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=dc7a0b38ca494ff09c656750fbe257db&lang=zh
*/
#pragma once
#include "response/response.h"

class CustomProtocol
{
public:
    std::string name;
    int ret;
    std::string session_id;
};

namespace nlohmann
{
template <>
struct adl_serializer<CustomProtocol>
{
    static void from_json(const json& j, CustomProtocol& out)
    {
        out.name = j.value("Name", "");
        out.ret = j.value("Ret", 0);
        out.session_id = j.value("SessionID", "");
    }
};
} // namespace nlohmann
using DeviceCustomProtocolResponse = Response<CustomProtocol>;