#pragma once

#include <string>
#include "json/json.hpp"

template <typename T>
class Message
{
public:
    std::string sn;   // 设备序列号
    std::string time; // 时间
    int seq;          // 消息序列号
    T data;
};

namespace nlohmann
{
template <typename T>
struct adl_serializer<Message<T>>
{
    static void from_json(const json& j, Message<T>& out)
    {
        if (j.contains("sn")) {
            out.sn = j.value("sn", "");
        } else if (j.contains("SerialNumber")) {
            out.sn = j.value("SerialNumber", "");
        }
        
        if (j.contains("time")) {
            out.time = j.value("time", "");
        }
        
        if (j.contains("seq")) {
            out.seq = j.value("seq", 0);
        }

        out.data = j;
    }
};
} // namespace nlohmann

#include "message/device_status_message.h"
#include "message/device_report_message.h"
#include "message/device_add_report_message.h"
#include "message/device_delect_report_message.h"
#include "message/device_family_group_del_report_message.h"
#include "message/device_del_share_report_message.h"
#include "message/device_reset_report_message.h"
#include "message/device_update_token_report_message.h"
#include "message/device_invite_report_message.h"
#include "message/device_userdel_report_message.h"
#include "message/device_passthrough_message.h"
#include "message/device_alarm_info_message.h"