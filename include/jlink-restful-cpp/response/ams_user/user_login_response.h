/*
功能：用户登录响应响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=90381a87380743e9b83110bf5517b274&lang=zh
*/
#pragma once
#include "response/response.h"

class UserLoginResult
{
public:
    std::string access_token;
};

using UserLoginResponse = Response<UserLoginResult>;

namespace nlohmann
{
template <>
struct adl_serializer<UserLoginResult>
{
    static void from_json(const json& j, UserLoginResult& out)
    {
        out.access_token = j.value("accessToken", "");
    }
};
} // namespace nlohmann
