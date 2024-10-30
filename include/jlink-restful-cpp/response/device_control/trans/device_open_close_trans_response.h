/*
功能：打开/关闭串口响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=fd8f1481a6974366ba91d7df38ec86ed&lang=zh
*/
#pragma once
#include "response/response.h"

class OpenCloseTrans
{
public:
    std::string name;
    int ret;
    std::string session_id;
};

namespace nlohmann
{
template <>
struct adl_serializer<OpenCloseTrans>
{
    static void from_json(const json& j, OpenCloseTrans& out)
    {
        out.name = j.value("Name", "");
        out.ret = j.value("Ret", 0);
        out.session_id = j.value("SessionID", "");
    }
};
} // namespace nlohmann
using DeviceOpenCloseTransResponse = Response<OpenCloseTrans>;