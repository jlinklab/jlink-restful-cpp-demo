/*
功能：关闭直播流响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=38ae09f37d874ea78bf517133a49b06a&lang=zh
*/
#pragma once
#include "response/response.h"

class CloseLiveStream
{
    // data为空
};

namespace nlohmann
{
template<>
struct adl_serializer<CloseLiveStream>
{
    static void from_json(const json&j, CloseLiveStream& out)
    {
        //data 为空
    }
};
}

using DeviceCloseLiveStreamResponse = Response<CloseLiveStream>;