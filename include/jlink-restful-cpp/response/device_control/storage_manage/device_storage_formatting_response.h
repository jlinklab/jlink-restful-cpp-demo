/*
功能：存储格式化响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=da8bf2c98fcb0ffcd52de7bff6b45ac9&lang=zh
*/
#pragma once
#include "response/response.h"

class StorageFormat
{
public:
    std::string name;
    int ret;
    std::string session_id;
};

namespace nlohmann
{
template <>
struct adl_serializer<StorageFormat>
{
    static void from_json(const json& j, StorageFormat& out)
    {
        out.name = j.value("Name", "");
        out.ret = j.value("Ret", 0);
        out.session_id = j.value("SessionID", "0x00000000");
    }
};
} // namespace nlohmann

using DeviceStorageFormatResponse = Response<StorageFormat>;