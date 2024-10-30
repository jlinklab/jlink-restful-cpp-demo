/*
功能：自定义协议透传请求体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=dc7a0b38ca494ff09c656750fbe257db&lang=zh
*/
#pragma once
#include "request/request.h"

class CustomProtocolRequest
{
public:
    std::string data;
    std::string data_type;
    std::string trans_type;
};

namespace nlohmann
{
template <>
struct adl_serializer<CustomProtocolRequest>
{
    static void to_json(json& j,const CustomProtocolRequest& in)
    {
        j = json{
            {"Data", in.data},
            {"DataType", in.data_type},
            {"TransType", in.trans_type}
        };
    }
};
} // namespace nlohmann
