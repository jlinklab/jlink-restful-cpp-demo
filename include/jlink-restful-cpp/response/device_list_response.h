#pragma once

#include "response.h"
#include "json/json.hpp"

class DeviceInfo
{
public:
    std::string sn;
    std::string username;
    std::string password;
    std::string nickname;
    std::string login_token;
};

using DeviceList = std::list<DeviceInfo>;
using DeviceListResponse = Response<DeviceList>;

namespace nlohmann
{
template <>
struct adl_serializer<DeviceInfo>
{
    static void from_json(const json& j, DeviceInfo& out)
    {
        out.sn = j.value("sn", "");
        out.username = j.value("username", "");
        out.password = j.value("password", "");
        out.nickname = j.value("nickname", "");
        out.login_token = j.value("login_token", "");
    }
};

template <>
struct adl_serializer<DeviceList>
{
    static void from_json(const json& j, DeviceList& out)
    {
        int count = j.value("deviceCount", 0);
        auto j_list = j["deviceList"];
        if (j_list.is_array()) {
            for (int i = 0; i < count; i++) {
                DeviceInfo info = j_list[0];
                out.push_back(info);
            }
        }
    }
};
} // namespace nlohmann