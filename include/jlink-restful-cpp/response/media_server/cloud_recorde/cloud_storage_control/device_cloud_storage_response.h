/*
功能：云存视频录像开关响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=5aed94ba94324341974609100e354ea4&lang=zh
*/
#pragma once
#include "response/response.h"

class CloudStorage
{
    // 响应为空
};

namespace nlohmann
{
template<>
struct adl_serializer<CloudStorage>
{
    static void from_json(const json&j, CloudStorage& out)
    {
        // 响应为空
    }
};
}

using DeviceCloudStorageResponse = Response<CloudStorage>;