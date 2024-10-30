/*
功能：手机用户注册
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=9b51262d76ce6da05962f0b4529971ba&lang=zh
*/
#pragma once
#include "request/request.h"

class PhoneRegInfo
{
public:
    std::string name;         // 用户名
    std::string password;     // 密码
    std::string confirm_pass; // 确认密码
    std::string phone;        // 手机号
    std::string verify_code;  // 手机验证码

    std::string to_string() const
    {
        return fmt::format(
            "name={}&password={}&confirmPass={}&phone={}&verCode={}", name, password, confirm_pass, phone, verify_code);
    }
};
