/*
功能：设置摄像机基本参数配置请求体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=d768ae3870fa40de8bf11908994602e5&lang=zh
*/
#pragma once
#include "request/request.h"

class ExposureParamRequest
{
public:
    std::string LeastTime;
    int Level;
    std::string MostTime;

    ExposureParamRequest()
        : Level(0)
    {
    }
};

class GainParamRequest
{
public:
    int AutoGain;
    int Gain;

    GainParamRequest()
        : AutoGain(0)
        , Gain(0)
    {
    }
};

class CameraSettingsRequest
{
public:
    int AeSensitivity;
    std::string ApertureMode;
    std::string BLCMode;
    std::string DayNightColor;
    int Day_nfLevel;
    int DncThr;
    int ElecLevel;
    std::string EsShutter;
    ExposureParamRequest exposureParam;
    GainParamRequest gainParam;
    int IRCUTMode;
    int InfraredSwap;
    int IrcutSwap;
    int Night_nfLevel;
    std::string PictureFlip;
    std::string PictureMirror;
    std::string RejectFlicker;
    std::string WhiteBalance;

    CameraSettingsRequest()
        : AeSensitivity(0)
        , Day_nfLevel(0)
        , DncThr(0)
        , ElecLevel(0)
        , IRCUTMode(0)
        , InfraredSwap(0)
        , IrcutSwap(0)
        , Night_nfLevel(0)
    {
    }
};

namespace nlohmann
{
template <>
struct adl_serializer<ExposureParamRequest>
{
    static void to_json(json& j, const ExposureParamRequest& in)
    {
        j = json{{"LeastTime", in.LeastTime}, {"Level", in.Level}, {"MostTime", in.MostTime}};
    }
};

template <>
struct adl_serializer<GainParamRequest>
{
    static void to_json(json& j, const GainParamRequest& in)
    {
        j = json{{"AutoGain", in.AutoGain}, {"Gain", in.Gain}};
    }
};

template <>
struct adl_serializer<CameraSettingsRequest>
{
    static void to_json(json& j, const CameraSettingsRequest& in)
    {
        j = json{{"AeSensitivity", in.AeSensitivity},
                 {"ApertureMode", in.ApertureMode},
                 {"BLCMode", in.BLCMode},
                 {"DayNightColor", in.DayNightColor},
                 {"Day_nfLevel", in.Day_nfLevel},
                 {"DncThr", in.DncThr},
                 {"ElecLevel", in.ElecLevel},
                 {"EsShutter", in.EsShutter},
                 {"ExposureParam", in.exposureParam},
                 {"GainParam", in.gainParam},
                 {"IRCUTMode", in.IRCUTMode},
                 {"InfraredSwap", in.InfraredSwap},
                 {"IrcutSwap", in.IrcutSwap},
                 {"Night_nfLevel", in.Night_nfLevel},
                 {"PictureFlip", in.PictureFlip},
                 {"PictureMirror", in.PictureMirror},
                 {"RejectFlicker", in.RejectFlicker},
                 {"WhiteBalance", in.WhiteBalance}};
    }
};
} // namespace nlohmann
