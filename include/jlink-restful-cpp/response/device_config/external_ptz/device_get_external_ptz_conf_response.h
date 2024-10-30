/*
功能：获取云台配置响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=616c1e17f7b243ee98e04c19eb250096&lang=zh
*/
#pragma once
#include "response/response.h"

class Attribute 
{
public:
    int baud_rate;
    std::string parity;
    int data_bits;
    int stop_bits;
};

class PTZ 
{
public:
    Attribute attribute;
    int device_no;
    int number_in_matrixs;
    int port_no;
    std::string protocol_name;
};

class PTZResponse 
{
public:
    std::string name;
    int ret;
    std::string session_id;
    std::vector<PTZ> uart_ptz;
};

namespace nlohmann 
{
template <>
struct adl_serializer<Attribute> {
    static void from_json(const json& j, Attribute& out) 
    {
        out.baud_rate = j.value("BaudRate", 9600);
        out.parity = j.value("Parity", "None");
        out.data_bits = j.value("DataBits", 8);
        out.stop_bits = j.value("StopBits", 1);
    }
};

template <>
struct adl_serializer<PTZ> 
{
    static void from_json(const json& j, PTZ& out) 
    {
        out.attribute = j.value("Attribute", Attribute());
        out.device_no = j.value("DeviceNo", 0);
        out.number_in_matrixs = j.value("NumberInMatrixs", 0); 
        out.port_no = j.value("PortNo", 0);
        out.protocol_name = j.value("ProtocolName", "NONE");
    }
};

template <>
struct adl_serializer<PTZResponse> 
{
    static void from_json(const json& j, PTZResponse& out) 
    {
        out.name = j.value("Name", "Uart.PTZ");
        out.ret = j.value("Ret", 100);
        out.session_id = j.value("SessionID", "0x00000000");
        out.uart_ptz = j.value("Uart.PTZ", std::vector<PTZ>());
    }
};
}  // namespace nlohmann
using DeviceExternalPTZConfResponse = Response<PTZResponse>;