/*
功能：开始升级固件
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=1175fc4e3160af8ec6f022e458f1f3b7&lang=zh
*/
#pragma once
#include "request/request.h"

class UpgradeFirmwareParams
{
public:
    std::string Partition;
    std::string FileName;
    std::string Date;
    int FileSize;
};

class UpgradeFirmwareRequest
{
public:
    std::string UUID;
    int Manual;
    std::vector<UpgradeFirmwareParams> Modules;
    std::string Type;
};

namespace nlohmann
{
template<>
struct adl_serializer<UpgradeFirmwareParams>
{
    static void to_json(json& j, const UpgradeFirmwareParams& in)
    {
        j = json{
            {"Partition", in.Partition},
            {"FileName", in.FileName},
            {"Date", in.Date},
            {"FileSize", in.FileSize}
        };
    }
};

template<>
struct adl_serializer<UpgradeFirmwareRequest>
{
    static void to_json(json& j, const UpgradeFirmwareRequest& in)
    {
        j = json{
            {"UUID", in.UUID},
            {"Manual", in.Modules},
            {"Modules", in.Modules},
            {"Type", in.Type}
        };
    }
};
}