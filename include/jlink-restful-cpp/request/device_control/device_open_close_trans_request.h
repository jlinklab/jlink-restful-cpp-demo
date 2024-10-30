/*
功能：打开/关闭串口请求体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=fd8f1481a6974366ba91d7df38ec86ed&lang=zh
*/
#pragma once
#include "request/request.h"

class OpenCloseTransRequest
{
public:
    std::string Action;
    std::string CommName;
};

namespace nlohmann
{
template <>
struct adl_serializer<OpenCloseTransRequest>
{
    static void to_json(json& j, const OpenCloseTransRequest& in)
    {
        j = json{
            {"Action", in.Action},
            {"CommName", in.CommName}
        };
    }
};
} // namespace nlohmann