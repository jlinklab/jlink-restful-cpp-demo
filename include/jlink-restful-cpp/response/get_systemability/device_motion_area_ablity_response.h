/*
功能：移动侦测能力响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=d17c198556240f1afb38b30b5bc5d2ad&lang=zh
*/
#pragma once
#include "response/response.h"

class MotionArea
{
public:
    int gridcolumn;
    int gridrow;
};

class MotionAreaResponse
{
public:
    MotionArea motin_area;
    std::string name;
    int ret;
    std::string sessionID;
};

namespace nlohmann
{
template <>
struct adl_serializer<MotionArea>
{
    static void from_json(const json& j, MotionArea& out)
    {
        out.gridcolumn = j.value("GridColumn", 0);
        out.gridrow = j.value("GridRow", 0);
    }
};

template<>
struct adl_serializer<MotionAreaResponse>
{
    static void from_json(const json& j, MotionAreaResponse& out)
    {
        out.motin_area = j.value("MotionArea", MotionArea());
        out.name = j.value("Name", "");
        out.ret = j.value("Ret", 0);
        out.sessionID = j.value("SessionID", "");
    }
};
} // namespace nlohmann
using DeviceMotionAreaResponse = Response<MotionAreaResponse>;