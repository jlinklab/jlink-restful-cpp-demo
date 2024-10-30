/*
功能：设置摄像机基本参数配置响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=d768ae3870fa40de8bf11908994602e5&lang=zh
*/
#pragma once
#include "response/response.h"

class SetCameraParam
{
public:
    std::string name;
    int ret;
    std::string session_id;
};

namespace nlohmann
{
template <>
struct adl_serializer<SetCameraParam>
{
    static void from_json(const json& j, SetCameraParam& out)
    {
        out.name = j.value("Name", "");
        out.ret = j.value("Ret", 0);
        out.session_id = j.value("SessionID", "");
    }
};
} // namespace nlohmann
using DeviceSetCameraParamConfResponse = Response<SetCameraParam>;