/*
功能：获取用户信息响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=b34293beb84957f8588669a7f81d5287&lang=zh
*/
#pragma once
#include "response/response.h"

class Authorizes
{
public:
    bool wxpms;
    bool wxbind;
    int member;
};

class UserInfoResponse
{
public:
    std::string id;
    std::string userId;
    std::string username;
    std::string mail;
    std::string phone;
    Authorizes authorizes;;
    int passUpdateTime;
};

namespace nlohmann
{
template <>
struct adl_serializer<Authorizes>
{
    static void from_json(const json& j, Authorizes& out)
    {
        out.wxpms = j.value("wxpms", false);
        out.wxbind = j.value("wxbind", false);
        out.member = j.value("member", 0);
    }
};

template<>
struct adl_serializer<UserInfoResponse>
{
    static void from_json(const json& j, UserInfoResponse& out)
    {
        out.id = j.value("id", "");
        out.userId = j.value("userId", "");
        out.username = j.value("username", "");
        out.mail = j.value("mail", "");
        out.phone = j.value("phone", "");
        out.authorizes = j.value("authorizes", Authorizes());
        out.passUpdateTime = j.value("passUpdateTime", 0);
    }
};
} // namespace nlohmann
using GetAMSUserInfoResponse = Response<UserInfoResponse>;