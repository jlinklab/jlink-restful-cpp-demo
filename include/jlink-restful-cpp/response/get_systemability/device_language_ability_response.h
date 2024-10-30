/*
功能：支持语言能力响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=de3f673a35f33921d34137b72d0ce512&lang=zh
*/
#pragma once
#include "response/response.h"

class MultiLanguage
{
public:
    std::vector<std::string> multi_language;
    std::string name;
    int ret;
    std::string sessionID;
};

namespace nlohmann
{
template <>
struct adl_serializer<MultiLanguage>
{
    static void from_json(const json& j, MultiLanguage& out)
    {
        out.multi_language = j.value("MultiLanguage", std::vector<std::string>());
        out.name = j.value("Name", "");
        out.ret = j.value("Ret", 0);
        out.sessionID = j.value("SessionID", "");
    }
};
} // namespace nlohmann
using DeviceLanguageAblity = Response<MultiLanguage>;