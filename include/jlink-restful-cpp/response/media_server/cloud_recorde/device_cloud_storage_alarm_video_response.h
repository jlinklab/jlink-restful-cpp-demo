/*
功能：获取云存报警视频列表响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=66142b2ca13c418d84085772a627d650&lang=zh
*/
#pragma once
#include "response/response.h"

class VideoInfo
{
public:
    std::string StartTime;
    std::string IndexFile;
    std::string StopTime;
    int PicFlag;
    std::string StorageBucket;
    int VideoSize;
};

class VideoResponse
{
public:
    int ret;
    std::vector<VideoInfo> VideoArray;
};

namespace nlohmann
{
template <>
struct adl_serializer<VideoInfo>
{
    static void from_json(const json& j, VideoInfo& out)
    {
        out.StartTime = j.value("StartTime", "");
        out.IndexFile = j.value("IndexFile", "");
        out.StopTime = j.value("StopTime", "");
        out.PicFlag = j.value("PicFlag", 0);
        out.StorageBucket = j.value("StorageBucket", "");
        out.VideoSize = j.value("VideoSize", 0);
    }
};

template <>
struct adl_serializer<VideoResponse>
{
    static void from_json(const json& j, VideoResponse& out)
    {
        out.ret = j.value("Ret", 0);
        out.VideoArray = j.value("VideoArray", std::vector<VideoInfo>());
    }
};
}
using DeviceCloudStorageAlarmVideoResponse = Response<VideoResponse>;
