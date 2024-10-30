/*
功能：变倍和聚焦控制响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=80410280fabf42d194a8efef97773424&lang=zh
*/
#pragma once
#include "response/response.h"

class ZoomFocus
{
public:
    std::string name;
    int ret;
    std::string session_id;
};

namespace nlohmann
{
template <>
struct adl_serializer<ZoomFocus>
{
    static void from_json(const json& j, ZoomFocus& out)
    {
        out.name = j.value("Name", "");
        out.ret = j.value("Ret", 0);
        out.session_id = j.value("SessionID", "");
    }
};
} // namespace nlohmann
using DeviceZoomFocusResponse = Response<ZoomFocus>;
