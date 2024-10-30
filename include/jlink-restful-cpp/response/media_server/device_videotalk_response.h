/*
功能：设备视频对讲响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=dacf4fca875d410a9beeb4186cd5d8ce&lang=zh
*/
#pragma once
#include "response/response.h"

class Videotalk
{
public:
    int ret;
    std::string url;
};

namespace nlohmann
{
template<>
struct adl_serializer<Videotalk>
{
    static void from_json(const json&j, Videotalk& out)
    {
        out.ret = j.value("Ret", 0);
        out.url = j.value("url", "");
    }
};
}

using DeviceVideotalkResponse = Response<Videotalk>;