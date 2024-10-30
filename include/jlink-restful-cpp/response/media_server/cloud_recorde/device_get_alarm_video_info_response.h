/*
功能：根据时间点获取报警视频片段信息响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=512d81cbb4dc4012bb38f2d5c004fdec&lang=zh
*/
#pragma once
#include "response/response.h"

class VideoDetail
{
public:
    std::string bucket;
    std::string et;
    std::string indx;
    std::string label;
    int picfg;
    std::string st;
    int vidsz;
};

class VideoDetailResponse
{
public:
    std::vector<VideoDetail> details;
    std::string msg;
};

namespace nlohmann
{
template <>
struct adl_serializer<VideoDetail>
{
    static void from_json(const json& j, VideoDetail& out)
    {
        out.bucket = j.value("bucket", "");
        out.et = j.value("et", "");
        out.indx = j.value("indx", "");
        out.label = j.value("label", nullptr); // Handle null case
        out.picfg = j.value("picfg", 0);
        out.st = j.value("st", "");
        out.vidsz = j.value("vidsz", 0);
    }
};

template <>
struct adl_serializer<VideoDetailResponse>
{
    static void from_json(const json& j, VideoDetailResponse& out)
    {
        out.details = j.value("details", std::vector<VideoDetail>()); // Adjust key as needed
        out.msg = j.value("msg", "");
    }
};
}
using DeviceVideoDetailByTimeResponse = Response<VideoDetailResponse>;
