/*
功能：修改密码响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=90381a87380743e9b83110bf5517b274&lang=zh
*/
#pragma once
#include "response/response.h"

class ModifyPassUnLoginResponse
{
public:
    std::string userId;
    std::string data;
};

namespace nlohmann
{
template <>
struct adl_serializer<ModifyPassUnLoginResponse>
{
    static void from_json(const json& j, ModifyPassUnLoginResponse& out)
    {
        out.userId = j.value("userId", "");
        out.data = j.value("data", "");
    }
};
} // namespace nlohmann
using UserModifyPassUnLoginResponse = Response<ModifyPassUnLoginResponse>;