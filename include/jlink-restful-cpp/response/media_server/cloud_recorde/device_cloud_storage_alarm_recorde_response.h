/*
功能：获取云存报警视频回放地址响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=2e08468f46564602d01ae8a244661672&lang=zh
*/
#pragma once
#include "response/response.h"

class AlarmRecorde
{
public:
    int ret;
    std::string url;
};

namespace nlohmann
{
template<>
struct adl_serializer<AlarmRecorde>
{
    static void from_json(const json&j, AlarmRecorde& out)
    {
        out.ret = j.value("Ret", 0);
        out.url = j.value("url", "");
    }
};
}

using DeviceAlarmRecordeResponse = Response<AlarmRecorde>;