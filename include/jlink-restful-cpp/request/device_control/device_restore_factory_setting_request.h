/*
功能：恢复出厂设置请求体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=1881639185144ebd995c2b2dbad40412&lang=zh
*/
#pragma once
#include "request/request.h"

class RestoreFactorySettingRequest
{
public:
    bool Account;
    bool XMModeSwitch;
    bool Preview;
    bool NetServer;
    bool Encode;
    bool NetCommon;
    bool CameraPARAM;
    bool CommPtz;
    bool Alarm;
    bool General;
    bool Record;
};

namespace nlohmann
{
template <>
struct adl_serializer<RestoreFactorySettingRequest>
{
    static void to_json(json& j, const RestoreFactorySettingRequest& in)
    {
        j = json{
            {"Account", in.Account},
            {"XMModeSwitch", in.XMModeSwitch},
            {"Preview", in.Preview},
            {"NetServer", in.NetServer},
            {"Encode", in.Encode},
            {"NetCommon", in.NetCommon},
            {"CameraPARAM", in.CameraPARAM},
            {"CommPtz", in.CommPtz},
            {"Alarm", in.Alarm},
            {"General", in.General},
            {"Record", in.Record}
        };
    }
};
}