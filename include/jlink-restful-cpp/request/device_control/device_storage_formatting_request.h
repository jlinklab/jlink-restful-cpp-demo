/*
功能：存储格式化请求体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=da8bf2c98fcb0ffcd52de7bff6b45ac9&lang=zh
*/
#pragma once
#include "request/request.h"

class StorageFormatRequest
{
public:
    std::string action;
    int partno;
    int aerialno;
};

namespace nlohmann
{
template <>
struct adl_serializer<StorageFormatRequest>
{
    static void to_json(json& j, const StorageFormatRequest& in)
    {
        j = json{
            {"Action", in.action},
            {"PartNo", in.partno},
            {"SerialNo", in.aerialno}
        };
    }
};
} // namespace nlohmann