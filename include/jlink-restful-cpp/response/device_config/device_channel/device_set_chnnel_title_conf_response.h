/*
功能：设置设备通道配置响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=6aeb7e3c61934269900948e144135982&lang=zh
*/
#pragma once
#include "response/response.h"

class SetChannelTitle
{
public:
    std::string name;
    int ret;
    std::string sessionID;
};

namespace nlohmann
{
template<>
struct adl_serializer<SetChannelTitle>
{
    static void from_json(const json& j, SetChannelTitle& out)
    {
        out.name = j.value("Name", "");
        out.ret = j.value("Ret", 0);
        out.sessionID = j.value("SessionID", "");
    }
};
}
using DeviceSetChnnelTitleConfResponse = Response<SetChannelTitle>;