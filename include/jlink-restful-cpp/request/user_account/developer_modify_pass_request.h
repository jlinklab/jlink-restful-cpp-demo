/*
功能：手机短信修改密码
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=219e6fd73c9922fbc3ca1c6240b14089&lang=zh
*/
#pragma once
#include "request/request.h"

class ModifyPass
{
public:
    std::string id;             // 用户id
    std::string phone;          // 手机号
    std::string verify_code;    // 手机验证码
    std::string new_pass;       // 新密码
    std::string confirm_pass;   // 确认密码

    std::string to_string() const
    {
        return fmt::format(
            "id={}&phone={}&verCode={}&newPass={}&confirmPass={}", id, phone, verify_code, new_pass, confirm_pass);
    }
};  
