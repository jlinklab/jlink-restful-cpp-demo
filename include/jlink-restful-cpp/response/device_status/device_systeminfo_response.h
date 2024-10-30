/*
功能：获取设备信息响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=072ab84b39954eb6adcfc33b050de121&lang=zh
*/
#pragma once
#include "response/response.h"

class SystemInfo
{
public:
    int AlarmInChannel;
    int AlarmOutChannel;
    int AudioInChannel;
    std::string BuildTime;
    int CombineSwitch;
    std::string DeviceRunTime;
    int DigChannel; 
    std::string EncryptVersion;
    int ExtraChannel;
    std::string HardWare;
    std::string HardWareVersion;
    std::string SerialNo;
    std::string SoftWareVersion;
    int TalkInChannel;
    int TalkOutChannel;
    std::string UpdataTime;
    std::string UpdataType;
    int VideoInChannel;
    int VideoOutChannel;
};

class SystemInfoResponse
{
public:
    std::string name;
    int ret;
    std::string session_id;
    SystemInfo system_info;
};

namespace nlohmann
{
template<>
struct adl_serializer<SystemInfo>
{
    static void from_json(const json& j, SystemInfo& out)
    {
        out.AlarmInChannel = j.value("AlarmInChannel", 0);
        out.AlarmOutChannel = j.value("AlarmOutChannel", 0);
        out.AudioInChannel = j.value("AudioInChannel", 0);
        out.BuildTime = j.value("BuildTime", "");
        out.CombineSwitch = j.value("CombineSwitch", 0);
        out.DeviceRunTime = j.value("DeviceRunTime", "");
        out.DigChannel = j.value("DigChannel", 0);
        out.EncryptVersion = j.value("EncryptVersion", "");
        out.ExtraChannel = j.value("ExtraChannel", 0);
        out.HardWare = j.value("HardWare", "");
        out.HardWareVersion = j.value("HardWareVersion", "");
        out.SerialNo = j.value("SerialNo", "");
        out.SoftWareVersion = j.value("SoftWareVersion", "");
        out.TalkInChannel = j.value("TalkInChannel", 0);
        out.TalkOutChannel = j.value("TalkOutChannel", 0);
        out.UpdataTime = j.value("UpdataTime", "");
        out.UpdataType = j.value("UpdataType", "");
        out.VideoInChannel = j.value("VideoInChannel", 0);
        out.VideoOutChannel = j.value("VideoOutChannel", 0);
    }
};

template<>
struct adl_serializer<SystemInfoResponse>
{
    static void from_json(const json& j, SystemInfoResponse& out)
    {
        out.name = j.value("Name", "");
        out.ret = j.value("Ret", 0);
        out.session_id = j.value("SessionID", "");
        out.system_info = j.value("SystemInfo", SystemInfo());
    }
};
}
using DeviceInfoResponse = Response<SystemInfoResponse>;