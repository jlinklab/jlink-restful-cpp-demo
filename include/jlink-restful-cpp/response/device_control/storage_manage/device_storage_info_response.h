/*
功能：存储信息查询响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=487daa3c3b92493ba03ec7790c741a71&lang=zh
*/
#pragma once
#include "response/response.h"

class Partition
{
public:
    int DriverType;
    bool IsCurrent;
    int LogicSerialNo;
    std::string NewEndTime;
    std::string NewStartTime;
    std::string OldEndTime;
    std::string OldStartTime;
    std::string RemainSpace;
    int Status;
    std::string TotalSpace;
};

class StorageInfo
{
public:
    int PartNumber;
    std::vector<Partition> Partition0;
    int PhysicalNo;
};

class StorageInfoResponse
{
public:
    std::string name;
    int ret;
    std::string session_id;
    std::vector<StorageInfo> storage_info;
};

namespace nlohmann
{
template <>
struct adl_serializer<Partition>
{
    static void from_json(const json& j, Partition& out)
    {
        out.DriverType = j.value("DriverType", 0);
        out.IsCurrent = j.value("IsCurrent", false);
        out.LogicSerialNo = j.value("LogicSerialNo", 0);
        out.NewEndTime = j.value("NewEndTime", "");
        out.NewStartTime = j.value("NewStartTime", "");
        out.OldEndTime = j.value("OldEndTime", "");
        out.OldStartTime = j.value("OldStartTime", "");
        out.RemainSpace = j.value("RemainSpace", "");
        out.Status = j.value("Status", 0);
        out.TotalSpace = j.value("TotalSpace", "");
    }
};

template <>
struct adl_serializer<StorageInfo>
{
    static void from_json(const json& j, StorageInfo& out)
    {
        out.PartNumber = j.value("PartNumber", 0);
        out.Partition0 = j.value("Partition", std::vector<Partition>{});
        out.PhysicalNo = j.value("PhysicalNo", 0); // Corrected spelling
    }
};

template <>
struct adl_serializer<StorageInfoResponse>
{
    static void from_json(const json& j, StorageInfoResponse& out)
    {
        out.name = j.value("Name", "");
        out.ret = j.value("Ret", 0);
        out.session_id = j.value("SessionID", "");
        out.storage_info = j.value("StorageInfo", std::vector<StorageInfo>());
    }
};// namespace nlohmann
}

using DeviceStorageInfoResponse = Response<StorageInfoResponse>;
