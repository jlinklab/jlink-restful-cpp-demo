/*
功能：设置通用配置请求体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=270aca4b56504d088dc0dc9156e370ff&lang=zh
*/
#pragma once
#include "request/request.h"

class SetGeneralRequest
{
public:
    int auto_logout;
    int font_size;
    int iran_calendar_enable;
    int local_no;
    std::string machine_name;
    std::string over_write;
    int screen_auto_shutdown;
    int screen_savetime;
    std::string video_output;

    SetGeneralRequest()
        : auto_logout(0),
          font_size(0),
          iran_calendar_enable(0),
          local_no(0),
          screen_auto_shutdown(0),
          screen_savetime(0)
    { }
};

namespace nlohmann
{
template <>
struct adl_serializer<SetGeneralRequest>
{
    static void to_json(json& j, const SetGeneralRequest& in)
    {
        j = json{
            {"AutoLogout", in.auto_logout},
            {"FontSize", in.font_size},
            {"IranCalendarEnable", in.iran_calendar_enable},
            {"LocalNo", in.local_no},
            {"MachineName", in.machine_name},
            {"OverWrite", in.over_write},
            {"ScreenAutoShutdown", in.screen_auto_shutdown},
            {"ScreenSaveTime", in.screen_savetime},
            {"VideoOutPut", in.video_output}
        };
    }
};
} // namespace nlohmann