
/*
功能：获取设备接口访问令牌(deviceToken)响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=d2f7b2d2991b48e591811cbf7a060bae&lang=zh
*/
#pragma once

#include "response/response.h"
#include "json/json.hpp"

class DeviceToken
{
public:
    std::string sn;
    std::string token;
};

namespace nlohmann
{
template <>
struct adl_serializer<DeviceToken>
{
    static void from_json(const json& j, DeviceToken& out)
    {
        // 打印传入的 JSON 对象
        // std::cout << "Received JSON: " << j.dump(4) << std::endl;

        // 直接检查 j 是否是一个数组
        if (j.is_array() && !j.empty()) {
            const auto& data_array = j;
            out.sn = data_array[0].value("sn", "");
            out.token = data_array[0].value("token", "");
        }
    }
};
} // namespace nlohmann

using DeviceTokenResponse = Response<DeviceToken>;