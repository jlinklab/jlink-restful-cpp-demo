/*
功能：设置外接云台配置请求体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=e6885d066b3f48d1bf80350df7c051b5&lang=zh
*/
#pragma once
#include "request/request.h"

class PTZDevice 
{
public:
    std::vector<nlohmann::json> Attribute;
    int DeviceNo;
    int NumberInMatrixs;
    int PortNo;
    std::string ProtocolName;

    PTZDevice()
        : DeviceNo(0)
        , NumberInMatrixs(0)
        , PortNo(0)
    { }
};

class UartPTZRequest 
{
public:
    std::vector<PTZDevice> PTZDevices;

    UartPTZRequest() {}
};

namespace nlohmann
{
template <>
struct adl_serializer<PTZDevice>
{
    static void to_json(json& j, const PTZDevice& ptz)
    {
        j = json{
            {"Attribute", ptz.Attribute},
            {"DeviceNo", ptz.DeviceNo},
            {"NumberInMatrixs", ptz.NumberInMatrixs},
            {"PortNo", ptz.PortNo},
            {"ProtocolName", ptz.ProtocolName}
        };
    }
};

template <>
struct adl_serializer<UartPTZRequest>
{
    static void to_json(json& j, const UartPTZRequest& uartPTZ)
    {
        j = json{
            {"Uart.PTZ", uartPTZ.PTZDevices}
        };
    }
};
}
