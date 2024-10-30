/*
功能：获取4G信号信息响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=fa0b0614f5374f09b5c847a52222a51a&lang=zh
*/
#pragma once
#include "response/response.h"

class FourGInfo
{
public:
    int signalLevel;
};

class FourGInfoResponse
{
public:
    std::string name;
    int ret;
    std::string session_id;
    FourGInfo fourG_info;
};

namespace nlohmann
{
template<>
struct adl_serializer<FourGInfo>
{
    static void from_json(const json& j, FourGInfo& out)
    {
        out.signalLevel = j.value("SignalLevel", 0);
    }
};

template<>
struct adl_serializer<FourGInfoResponse>
{
    static void from_json(const json& j, FourGInfoResponse& out)
    {
        out.name = j.value("Name", "");
        out.ret = j.value("Ret",  0);
        out.session_id = j.value("SesionID", "");
        out.fourG_info = j.value("4GInfo", FourGInfo());
    }
};
}

using Device4GInfoResponse = Response<FourGInfoResponse>;