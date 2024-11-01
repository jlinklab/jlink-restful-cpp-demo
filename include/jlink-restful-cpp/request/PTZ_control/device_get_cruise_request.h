/*
功能：云台获取巡航路径配置请求体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=6f7d887c974444f4a18040fc2db07ae2&lang=zh
*/
#pragma once
#include "request/request.h"

class GetCruiseParams
{
public:
    int id;
    std::string Name;
    std::string Time;

    GetCruiseParams() : id(0) { }
};

class GetCruiseRequest
{
public:
    std::string Name;
    std::vector<GetCruiseParams> id;
};

namespace nlohmann
{
template <>
struct adl_serializer<GetCruiseParams>
{
    static void to_json(json& j, const GetCruiseParams& in)
    {
        j = json{
            {"id", in.id},
            {"Name", in.Name},
            {"Time", in.Time}
        };
    }
};

template <>
struct adl_serializer<GetCruiseRequest>
{
    static void to_json(json& j, const GetCruiseRequest& in)
    {
        j = json{
            {"Name", in.Name},
            {"id", {
                {"Tour", in.id}
            }}
        };
    }
};
} // namespace nlohmann