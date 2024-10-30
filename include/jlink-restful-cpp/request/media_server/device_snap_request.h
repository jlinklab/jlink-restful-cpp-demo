/*
功能：设备抓图请求体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=ea2911c2f59d4975abc3dcad69ef396a&lang=zh
*/
#pragma once
#include "request/request.h"

class SnapRequest
{
public:
    int Channel;
    int PicType;
};

namespace nlohmann
{
template <>
struct adl_serializer<SnapRequest>
{
    static void to_json(json& j, const SnapRequest& in)
    {
        j = json{
            {"Channel", in.Channel},
            {"PicType", in.PicType}
        };
    }
};
} // namespace nlohmann