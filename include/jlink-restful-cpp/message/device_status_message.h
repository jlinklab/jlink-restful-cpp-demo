/*
功能：设备状态变更通知
描述：详见https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=c2d26b7d77074935973f9c5a8e84ebca&lang=zh
*/
#pragma once

#include <stdint.h>
#include <string>
#include <vector>
#include "message.h"

class DeviceStatus0
{
public:
    uint64_t timestamp;                // 时间戳
    std::string prop_code;             // 属性编码
    std::string prop_value;            // 属性值
    int prop_auth;                     // 是否被认证
    std::vector<std::string> channels; // 通道是否连接
};

using DeviceStatusList = std::list<DeviceStatus0>;
using DeviceStatusMsg = Message<DeviceStatusList>;

namespace nlohmann
{
template <>
struct adl_serializer<DeviceStatus0>
{
    static void from_json(const json& j, DeviceStatus0& out)
    {
        out.timestamp = j.value("propTimeMillis", 0);
        out.prop_code = j.value("propCode", "");
        out.prop_value = j.value("propValue", "");
        out.prop_auth = j.value("propAuth", 0);
        // out.channels = j.value("propChannel");
    }
};

template <>
struct adl_serializer<DeviceStatusList>
{
    static void from_json(const json& j, DeviceStatusList& out)
    {   
        if (j.contains("props") && j["props"].is_array()) {
            for(int i = 0; i < j["props"].size(); i++) {
                DeviceStatus0 dev_status = j["props"][i];
                out.push_back(dev_status);
            }
        }
    }
};
}
