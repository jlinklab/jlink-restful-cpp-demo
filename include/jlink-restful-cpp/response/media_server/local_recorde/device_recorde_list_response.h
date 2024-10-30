/*
功能：获取回放列表响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=4b1516da5763439a9bc7175d7ac7d246&lang=zh
*/
#pragma once
#include "response/response.h"

class OPFile
{
public:
    std::string BeginTime;
    int DiskNo;
    std::string EndTime;
    std::string FileLength;
    std::string FileName;
    int SerialNo;
};

class OPFileQueryResponse
{
public:
    std::string name;
    int ret;
    std::string session_id;
    std::vector<OPFile> OPFileQuery;
    std::string msg;
};

namespace nlohmann
{
template <>
struct adl_serializer<OPFile>
{
    static void from_json(const json& j, OPFile& out)
    {
        out.BeginTime = j.value("BeginTime", "");
        out.DiskNo = j.value("DiskNo", 0);
        out.EndTime = j.value("EndTime", "");
        out.FileLength = j.value("FileLength", "");
        out.FileName = j.value("FileName", "");
        out.SerialNo = j.value("SerialNo", 0);
    }
};

template <>
struct adl_serializer<OPFileQueryResponse>
{
    static void from_json(const json& j, OPFileQueryResponse& out)
    {
        out.name = j.value("Name", "");
        out.ret = j.value("Ret", 0);
        out.session_id = j.value("SessionID", "");
        out.OPFileQuery = j.value("OPFileQuery", std::vector<OPFile>());
        out.msg = j.value("msg", "");
    }
};
}

using DeviceOPFileQueryResponse = Response<OPFileQueryResponse>;
