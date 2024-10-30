/*
功能：区域遮挡能力响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=d17c198556240f1afb38b30b5bc5d2ad&lang=zh
*/
#pragma once
#include "response/response.h"

class BlindCapability
{
public:
    int blindcoverNum;
};

class BlindCapabilityResponse
{
public:
    BlindCapability blind_cap_ability;
    std::string name;
    int ret;
    std::string session_id;
};

namespace nlohmann
{
template <>
struct adl_serializer<BlindCapability>
{
    static void from_json(const json& j, BlindCapability& out)
    {
        out.blindcoverNum = j.value("BlindCapability", 0);
    }
};

template<>
struct adl_serializer<BlindCapabilityResponse>
{
    static void from_json(const json& j, BlindCapabilityResponse& out)
    {
        out.blind_cap_ability = j.value("BlindCapability", BlindCapability());
        out.name = j.value("Name", "");
        out.ret = j.value("Ret", 0);
        out.session_id = j.value("SessionID", "");
    }
};
} // namespace nlohmann

using DeviceBlindCapabilityResponse = Response<BlindCapabilityResponse>;