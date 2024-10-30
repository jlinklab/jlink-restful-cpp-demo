/*
功能：获取摄像机基本参数配置响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=2e7b9a3db9b04914b4e90a45fb55e6a1&lang=zh
*/
#pragma once
#include "response/response.h"

struct ExposureParam
{
    std::string least_time;
    int level;
    std::string most_time;
};

struct GainParam
{
    int auto_gain;
    int gain;
};

struct CameraParam
{
    int ae_sensitivity;
    std::string aperture_mode;
    std::string blc_mode;
    std::string day_night_color;
    int day_nf_level;
    int dnc_thr;
    int elec_level;
    std::string es_shutter;
    ExposureParam exposure_param;
    GainParam gain_param;
    int ircut_mode;
    int infrared_swap;
    int ircut_swap;
    int night_nf_level;
    std::string picture_flip;
    std::string picture_mirror;
    std::string reject_flicker;
    std::string white_balance;
};

struct CameraParamResponse
{
    std::string name;
    int ret;
    std::string session_id;
    std::vector<CameraParam> camera_params;
};

namespace nlohmann
{
template <>
struct adl_serializer<ExposureParam>
{
    static void from_json(const json& j, ExposureParam& out)
    {
        out.least_time = j.value("LeastTime", "");
        out.level = j.value("Level", 0);
        out.most_time = j.value("MostTime", "");
    }
};

template <>
struct adl_serializer<GainParam>
{
    static void from_json(const json& j, GainParam& out)
    {
        out.auto_gain = j.value("AutoGain", 0);
        out.gain = j.value("Gain", 0);
    }
};

template <>
struct adl_serializer<CameraParam>
{
    static void from_json(const json& j, CameraParam& out)
    {
        out.ae_sensitivity = j.value("AeSensitivity", 0);
        out.aperture_mode = j.value("ApertureMode", "");
        out.blc_mode = j.value("BLCMode", "");
        out.day_night_color = j.value("DayNightColor", "");
        out.day_nf_level = j.value("Day_nfLevel", 0);
        out.dnc_thr = j.value("DncThr", 0);
        out.elec_level = j.value("ElecLevel", 0);
        out.es_shutter = j.value("EsShutter", "");
        out.exposure_param = j.value("ExposureParam", ExposureParam());
        out.gain_param = j.value("GainParam", GainParam());
        out.ircut_mode = j.value("IRCUTMode", 0);
        out.infrared_swap = j.value("InfraredSwap", 0);
        out.ircut_swap = j.value("IrcutSwap", 0);
        out.night_nf_level = j.value("Night_nfLevel", 0);
        out.picture_flip = j.value("PictureFlip", "");
        out.picture_mirror = j.value("PictureMirror", "");
        out.reject_flicker = j.value("RejectFlicker", "");
        out.white_balance = j.value("WhiteBalance", "");
    }
};

template <>
struct adl_serializer<CameraParamResponse>
{
    static void from_json(const json& j, CameraParamResponse& out)
    {
        out.name = j.value("Name", "");
        out.ret = j.value("Ret", 0);
        out.session_id = j.value("SessionID", "");
        out.camera_params = j.value("Camera.Param", std::vector<CameraParam>());
    }
};
}  // namespace nlohmann

using DeviceCameraParamConfResponse = Response<CameraParamResponse>;
