/*
功能：摄像机参数能力响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=f93977c87ba5cdff07a119a7ba9523eb&lang=zh
*/
#pragma once
#include "response/response.h"

class Camera
{
public:
    int count;
    int elecLevel;
    int isFishLens;
    int luminance;
    std::vector<std::string> speeds;
    int status;
    int supportIntellDoubleLight;
    int supportPreventOverExpo;
    std::string version;
};

class CameraResponse
{
public:
    Camera camera;
    std::string name;
    int ret;
    std::string session_id;
};

namespace nlohmann
{
template <>
struct adl_serializer<Camera>
{
    static void from_json(const json& j, Camera& out)
    {
        out.count = j.value("Count", 0);
        out.elecLevel = j.value("ElecLevel", 0);
        out.isFishLens = j.value("IsFishLens", 0);
        out.luminance = j.value("Luminance", 0);
        out.speeds = j.value("Speeds", std::vector<std::string>());
        out.status = j.value("Status", 0);
        out.supportIntellDoubleLight = j.value("SupportIntellDoubleLight", 0);
        out.supportPreventOverExpo = j.value("SupportPreventOverExpo", 0);
        out.version = j.value("Version", "");
    }
};

template<>
struct adl_serializer<CameraResponse>
{
    static void from_json(const json& j, CameraResponse& out)
    {
        out.camera = j.value("Camera", Camera());
        out.name = j.value("Name", "");
        out.ret = j.value("Ret", 0);
        out.session_id = j.value("SessionID", "");
    }
};
}

using DeviceCamerAblityResponse = Response<CameraResponse>;