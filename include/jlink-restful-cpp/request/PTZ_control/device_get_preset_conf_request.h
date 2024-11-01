/*
功能：云台获取预置点配置请求体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=6f7d887c974444f4a18040fc2db07ae2&lang=zh
*/
#pragma once
#include "request/request.h"

class GetPresetParams
{
public:
    int Id;
    std::string PresetName;

    GetPresetParams() : Id(0) { }
};

class GetPresetRequest
{
public:
    std::vector<GetPresetParams> preset_params;
};

namespace nlohmann
{
template <>
struct adl_serializer<GetPresetParams>
{
    static void to_json(json& j, const GetPresetParams& in)
    {
        j = json{
            {"Id", in.Id},
            {"PresetName", in.PresetName}
        };
    }
};

template <>
struct adl_serializer<GetPresetRequest>
{
    static void to_json(json& j, const GetPresetRequest& in)
    {
        {
            j = in.preset_params;
        }
    }
};
} // namespace nlohmann