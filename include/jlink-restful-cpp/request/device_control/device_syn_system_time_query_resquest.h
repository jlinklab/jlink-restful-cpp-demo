/*
功能：同步系统时间请求体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=a39c8602ae7e488e9ad2048ca10df1fe&lang=zh
*/
#pragma once
#include "request/request.h"

class SynSystemTimeRequest
{
public:
    std::string DateTime;
};

namespace nlohmann
{
template <>
struct adl_serializer<SynSystemTimeRequest>
{
    static void to_json(json& j, const SynSystemTimeRequest& in)
    {
        j = in.DateTime;
    }
};
} // namespace nlohmann