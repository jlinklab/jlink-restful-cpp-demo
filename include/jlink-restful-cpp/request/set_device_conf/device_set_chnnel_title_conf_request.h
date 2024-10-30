/*
功能：设置设备通道配置请求体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=6aeb7e3c61934269900948e144135982&lang=zh
*/
#pragma once
#include "request/request.h"

class SetChannelTitleRequest
{
public:
    std::vector<std::string> ChannelTitle;
};

namespace nlohmann
{
template <>
struct adl_serializer<SetChannelTitleRequest>
{
    static void to_json(json& j, const SetChannelTitleRequest& in)
    {
        j = in.ChannelTitle; // ChannelTitle
    }
};
} // namespace nlohmann