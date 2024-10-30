/*
功能：主辅码流录像能力响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=5ed00bc00d944a74adf8e7bf94e1b0c2&lang=zh
*/
#pragma once
#include "response/response.h"

class SupportExtRecord
{
public:
    std::string AbilityPram;
};

class SupportExtRecordResponse
{
public:
    std::string name;
    int ret;
    std::string sessionID;
    SupportExtRecord supportextrecord;
};

namespace nlohmann
{
template<>
struct adl_serializer<SupportExtRecord>
{
    static void from_json(const json& j, SupportExtRecord& out)
    {
        out.AbilityPram = j.value("AbilityPram", "");
    }
};

template<>
struct adl_serializer<SupportExtRecordResponse>
{
    static void from_json(const json& j, SupportExtRecordResponse& out)
    {
        out.name = j.value("Name", "");
        out.ret = j.value("Ret", 0);
        out.sessionID = j.value("SessionID", "");
        out.supportextrecord = j.value("SupportExtRecord", SupportExtRecord());
    }
};
}

using DeviceSupportExtRecordAbilityResponse = Response<SupportExtRecordResponse>;