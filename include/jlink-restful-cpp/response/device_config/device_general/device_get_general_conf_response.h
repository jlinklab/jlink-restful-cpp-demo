/*
功能：获取设备通用配置响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=8970b40d0c0c4321a5bb146e2bdc8352&lang=zh
*/
#pragma once
#include "response/response.h"

class General
{
public:
    int auto_logout;
    int font_size;
    int iran_calendar_enable;
    int local_no;
    std::string machine_name;
    std::string over_write;
    int screen_auto_shutdown;
    int screen_save_time;
    std::string video_output;
};

class GeneralResponse
{
public:
    std::string name;
    General general_general;
    int ret;
    std::string session_id;
};

namespace nlohmann
{
template <>
struct adl_serializer<General>
{
    static void from_json(const json& j, General& out)
    {
        out.auto_logout = j.value("AutoLogout", 0);
        out.font_size = j.value("FontSize", 24);
        out.iran_calendar_enable = j.value("IranCalendarEnable", 0);
        out.local_no = j.value("LocalNo", 0);
        out.machine_name = j.value("MachineName", "");
        out.over_write = j.value("OverWrite", "OverWrite");
        out.screen_auto_shutdown = j.value("ScreenAutoShutdown", 10);
        out.screen_save_time = j.value("ScreenSaveTime", 0);
        out.video_output = j.value("VideoOutPut", "Auto");
    }
};

template <>
struct adl_serializer<GeneralResponse>
{
    static void from_json(const json& j, GeneralResponse& out)
    {
        out.name = j.value("Name", "");
        out.general_general = j.value("General.General", General());
        out.ret = j.value("Ret", 0);
        out.session_id = j.value("SessionID", "");
    }
};

}  // namespace nlohmann

using DeviceGeneralConfResponse = Response<GeneralResponse>;
