/*
功能：用户登录
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=bd232d78fff12c7b6cabb4f5eaf1288b&lang=zh
*/
#pragma once
#include "request/request.h"

class UserLoginInfo
{
public:
    std::string account;  // 账号
    std::string password; // 密码

    std::string to_string() const
    {
        return fmt::format("account={}&pass={}", account, password);
    }
};
