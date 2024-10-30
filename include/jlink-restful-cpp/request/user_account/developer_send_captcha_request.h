/*
功能：发送验证码
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=470293fc5586be3c7584dceb2b304c76&lang=zh
*/
#pragma once
#include "request/request.h"
#include "fmt/core.h"

class SendCaptcha
{
public:
    std::string phone; // 手机号
    std::string type;  // 类型

    std::string to_string() const
    {
        return fmt::format("phone={}&type={}", phone, type);
    }
};
