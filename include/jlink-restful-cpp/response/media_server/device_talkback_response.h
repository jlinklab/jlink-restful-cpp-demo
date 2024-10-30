/*
功能：设备语音对讲响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=8ec4967ab4284e4ea30024fb259ef8be&lang=zh
*/
#pragma once
#include "response/response.h"

class TalkBack
{
public:
    int ret;
    std::string url;
    std::string ret_msg;
};

namespace nlohmann
{
template<>
struct adl_serializer<TalkBack>
{
    static void from_json(const json&j, TalkBack& out)
    {
        out.ret = j.value("Ret", 0);
        out.url = j.value("url", "");
        out.ret_msg = j.value("RetMsg", "");
    }
};
}

using DeviceTalkBackResponse = Response<TalkBack>;