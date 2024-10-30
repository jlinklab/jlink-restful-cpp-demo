/*
功能：卡回放日历列表响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=137789bc6fd842f69a452810eae6423e&lang=zh
*/
#pragma once
#include "response/response.h"

class CalendarEntry
{
public:
    std::string date;
    int is_exist;
};

class OPSCalendarResponse
{
public:
    std::string name;
    int ret;
    std::string session_id;
    std::vector<CalendarEntry> CalendarList;
    std::string msg;
};

namespace nlohmann
{
template <>
struct adl_serializer<CalendarEntry>
{
    static void from_json(const json& j, CalendarEntry& out)
    {
        out.date = j.value("date", "");
        out.is_exist = j.value("is_exist", 0);
    }
};

template <>
struct adl_serializer<OPSCalendarResponse>
{
    static void from_json(const json& j, OPSCalendarResponse& out)
    {
        out.name = j.value("Name", "");
        out.ret = j.value("Ret", 0);
        out.session_id = j.value("SessionID", "");
        out.CalendarList = j.value("CalendarList", std::vector<CalendarEntry>());
        out.msg = j.value("msg", "");
    }
};
}

using DeviceOPSCalendarResponse = Response<OPSCalendarResponse>;
