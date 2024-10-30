/*
功能：检测固件新版本响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=9443bea1e84a0f08bd67ba4f7ad0ccf7&lang=zh
*/
#pragma once
#include "response/response.h"

class Module
{
public:
    std::string ChangeLog;
    std::string Date;
    std::string DevID;
    int FileLevel;
    std::string FileName;
    int FileSize;
    std::string Partition;
};

class OPVersionRep
{
public:
    std::vector<Module> Modules;
    std::string Type;
};

class OPVersionRepResponse
{
public:
    std::string name;
    int ret;
    std::string session_id;
    OPVersionRep OPVersionRepData;
};

namespace nlohmann
{
template <>
struct adl_serializer<Module>
{
    static void from_json(const json& j, Module& out)
    {
        out.ChangeLog = j.value("ChangeLog", "");
        out.Date = j.value("Date", "");
        out.DevID = j.value("DevID", "");
        out.FileLevel = j.value("FileLevel", 0);
        out.FileName = j.value("FileName", "");
        out.FileSize = j.value("FileSize", 0);
        out.Partition = j.value("Partition", "");
    }
};

template <>
struct adl_serializer<OPVersionRep>
{
    static void from_json(const json& j, OPVersionRep& out)
    {
        out.Modules = j.value("Modules", std::vector<Module>());
        out.Type = j.value("Type", "");
    }
};

template <>
struct adl_serializer<OPVersionRepResponse>
{
    static void from_json(const json& j, OPVersionRepResponse& out)
    {
        out.name = j.value("Name", "");
        out.ret = j.value("Ret", 0);
        out.session_id = j.value("SessionID", "");
        out.OPVersionRepData = j.value("OPVersionRep", OPVersionRep());
    }
};
} // namespace nlohmann
using DeviceFirmVersionResponse = Response<OPVersionRepResponse>;
