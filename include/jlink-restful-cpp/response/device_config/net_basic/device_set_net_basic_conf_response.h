/*
功能：设置网络基础配置响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=e1e27b8be1724065897590046789cb54&lang=zh
*/
#pragma once
#include "response/response.h"

class SetNetCommon
{
public:
    std::string name;
    int ret;
    std::string session_id;
};

namespace nlohmann
{
template <>
struct adl_serializer<SetNetCommon>
{
    static void from_json(const json& j, SetNetCommon& out)
    {
        out.name = j.value("Name", "");
        out.ret = j.value("Ret", 0);
        out.session_id = j.value("SessionID", "0x00000000");
    }
};
} // namespace nlohmann

using DeviceSetNetBasicConfResponse = Response<SetNetCommon>;