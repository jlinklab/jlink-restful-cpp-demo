/*
功能：设备抓图响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=ea2911c2f59d4975abc3dcad69ef396a&lang=zh
*/
#pragma once
#include "response/response.h"

class Snap
{
public:
    int ret;
    std::string image;
};

namespace nlohmann
{
template<>
struct adl_serializer<Snap>
{
    static void from_json(const json&j, Snap& out)
    {
        out.ret = j.value("Ret", 0);
        out.image = j.value("image", "");
    }
};
}

using DeviceSnapResponse = Response<Snap>;