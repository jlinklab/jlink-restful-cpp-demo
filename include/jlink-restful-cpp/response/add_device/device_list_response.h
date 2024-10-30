/*
功能：获取设备列表响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=90381a87380743e9b83110bf5517b274&lang=zh
*/
#pragma once
#include <list>
#include "response/response.h"

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
        if (j.contains("deviceList") && j["deviceList"].is_array() && !j["deviceList"].empty()) {
            auto j_list = j["deviceList"];
            if (j_list.is_array()) {
                for (int i = 0; i < count; i++) {
                    DeviceInfo info = j_list[i];
                    out.push_back(info);
                }
            }
        }
    }
};
} // namespace nlohmann
