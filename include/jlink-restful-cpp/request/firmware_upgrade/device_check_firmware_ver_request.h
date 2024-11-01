/*
功能：检测固件新版本请求体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=9443bea1e84a0f08bd67ba4f7ad0ccf7&lang=zh
*/
#pragma once
#include "request/request.h"

class CheckFirmwareVerRequest
{
public:
    std::string CurVersion;
    std::string DevID;
    std::string DevType;
    int Expect;
    std::string Language;
    int Manual;
    std::string SN;
    std::string UUID;

    CheckFirmwareVerRequest() : Expect(0), Manual(0)
    { }
};

namespace nlohmann
{
template <>
struct adl_serializer<CheckFirmwareVerRequest>
{
    static void to_json(json& j, const CheckFirmwareVerRequest& in)
    {
        j = json{
            {"CurVersion", in.CurVersion},
            {"DevID", in.DevID},
            {"DevType", in.DevType},
            {"Expect", in.Expect},
            {"Language", in.Language},
            {"Manual", in.Manual},
            {"SN", in.SN},
            {"UUID", in.UUID}
        };
    }
};
} // namespace nlohmann