/*
功能：同步UTC时间请求体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=4da974c55768c699ee6637415084c15e&lang=zh
*/
#pragma once
#include "request/request.h"

class SynUTCRequest
{
public:
    std::string DateTime;
};

namespace nlohmann
{
template <>
struct adl_serializer<SynUTCRequest>
{
    static void to_json(json& j, const SynUTCRequest& in)
    {
        j = in.DateTime;
    }
};
} // namespace nlohmann