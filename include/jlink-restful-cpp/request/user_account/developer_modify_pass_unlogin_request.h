/*
功能：修改密码
描述：
*/
#pragma once
#include "request/request.h"

class ModifyPass_UnLogin
{
public:
    std::string mail;           // 邮箱
    std::string phone;          // 手机号
    std::string verify_code;    // 手机验证码
    std::string head;

    std::string to_string() const
    {
        return fmt::format(
            "mail={}&phone={}&verCode={}&head={}", mail, phone, verify_code, head);
    }
};  
