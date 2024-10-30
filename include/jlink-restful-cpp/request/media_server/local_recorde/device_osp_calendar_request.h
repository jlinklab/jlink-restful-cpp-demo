/*
功能：卡回放日历列表请求体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=137789bc6fd842f69a452810eae6423e&lang=zh
*/
#pragma once
#include "request/request.h"

class OPSCalendarRequest
{
public:
    std::string Event;
    int Channel;
    std::string FileType;
    int Month;
    int Year;
};

namespace nlohmann
{
template <>
struct adl_serializer<OPSCalendarRequest>
{
    static void to_json(json& j, const OPSCalendarRequest& in)
    {
        j = json{
            {"Event", in.Event},
            {"Channel", in.Channel},
            {"FileType", in.FileType},
            {"Month", in.Month},
            {"Year", in.Year}
        };
    }
};
} // namespace nlohmann