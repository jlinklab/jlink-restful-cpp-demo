/*
功能：本地录像切换主辅码流响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=88ce3666507945298e632e4fe9da9fb8&lang=zh
*/
#pragma once
#include "response/response.h"

class SwitchStream
{
public:
    int ret;
    std::string name;
};

namespace nlohmann
{
template<>
struct adl_serializer<SwitchStream>
{
    static void from_json(const json&j, SwitchStream& out)
    {
        out.ret = j.value("Ret", 0);
        out.name = j.value("Name", "");
    }
};
}

using DeviceSwitchStreamResponse = Response<SwitchStream>;