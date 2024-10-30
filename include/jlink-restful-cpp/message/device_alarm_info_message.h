/*
功能：告警消息通知
描述：详见https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=5249eb1724c3439b81d523078cf24ea9&lang=zh
*/
#pragma once

#include <stdint.h>
#include <string>
#include <vector>
#include "message.h"

class AlarmInfoMsg
{
public:
    std::string alarm_event;
    std::string alarm_id; 
    std::string alarm_msg;
    std::string alarm_time; 
    std::string auth_code;
    std::string channel; 
    std::string serial_number;
    std::string status;
};

namespace nlohmann
{
template<>
struct adl_serializer<AlarmInfoMsg>
{
    static void from_json(const json& j, AlarmInfoMsg& out)
    {
        out.alarm_event = j.value("AlarmEvent", "");
        out.alarm_id = j.value("AlarmId", "");
        out.alarm_msg = j.value("AlarmMsg", "");
        out.alarm_time = j.value("AlarmTime", "");
        out.auth_code = j.value("AuthCode", "");
        out.channel = j.value("Channel", "");
        out.serial_number = j.value("SerialNumber", "");
        out.status = j.value("Status", "");
    }
};
}