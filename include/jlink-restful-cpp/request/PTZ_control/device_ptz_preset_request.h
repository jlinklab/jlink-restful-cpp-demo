/*
功能：云台预置点功能请求体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=50b75d2e72374ba8b2252beeb751634b&lang=zh
*/
#pragma once
#include "request/request.h"

class PTZPreSetRequest
{
public:
    std::string Preset;
    std::string Channel;
    std::string PresetName;
};

class SetPresetRequest
{
public:
    std::string Command;
    PTZPreSetRequest Parameter;
};

namespace nlohmann
{
template <>
struct adl_serializer<PTZPreSetRequest>
{
    static void to_json(json& j, const PTZPreSetRequest& in)
    {
        j = json{
            {"Preset", in.Preset},
            {"Channel", in.Channel},
            {"PresetName", in.PresetName}
        };
    }
};

template <>
struct adl_serializer<SetPresetRequest>
{
    static void to_json(json& j, const SetPresetRequest& in)
    {
        j = json{
            {"Command", in.Command},
            {"Parameter", in.Parameter}
        };
    }
};
} // namespace nlohmann