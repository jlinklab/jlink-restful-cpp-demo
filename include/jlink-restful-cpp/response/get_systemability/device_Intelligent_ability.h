/*
功能：智能分析能力响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=4a595ccfe6ffe32dd41e31daa8ea88e7&lang=zh
*/
#pragma once
#include "response/response.h"

class LimitOSC
{
public:
    int AreaMaxLineNum;
    int AreaNum;
    int Rectangle;
};

class LimitPEA
{
public:
    int AreaMaxLineNum;
    int AreaNum;
    int LineNum;
    int Rectangle;
};

class Intelligent
{
public:
    std::string AlgorithmAVD;
    std::string AlgorithmCPC;
    std::string AlgorithmPEA;
    std::string IntelAVD;
    std::string IntelCPC;
    std::string IntelPEA;
    LimitOSC limitosc;
    LimitPEA limitpea;
};

class IntelligentResponse
{
public:
    Intelligent intelligent;
    std::string name;
    int ret;
    std::string sessionID;
};

namespace nlohmann
{
template<>
struct adl_serializer<LimitOSC>
{
    static void from_json(const json& j, LimitOSC& out)
    {
        out.AreaMaxLineNum = j.value("AreaMaxLineNum", 0);
        out.AreaNum = j.value("AreaNum", 0);
        out.Rectangle = j.value("Rectangle", 0);
    }
};

template<>
struct adl_serializer<LimitPEA>
{
    static void from_json(const json& j, LimitPEA& out)
    {
        out.AreaMaxLineNum = j.value("AreaMaxLineNum", 0);
        out.AreaNum = j.value("AreaNum", 0);
        out.LineNum = j.value("LineNum", 0);
        out.Rectangle = j.value("Rectangle", 0);
    }
};

template<>
struct adl_serializer<Intelligent>
{
    static void from_json(const json& j, Intelligent& out)
    {
        out.AlgorithmAVD = j.value("AlgorithmAVD", "");
        out.AlgorithmCPC = j.value("AlgorithmCPC", "");
        out.AlgorithmPEA = j.value("AlgorithmPEA", "");
        out.IntelAVD = j.value("IntelAVD", "");
        out.IntelCPC = j.value("IntelCPC", "");
        out.IntelPEA = j.value("IntelPEA", "");
        if(j.contains("LimitOSC") && j["LimitOSC"].is_object())
        {
            out.limitosc = j["LimitOSC"].get<LimitOSC>();
        }
        if(j.contains("LimitPEA") && j["LimitPEA"].is_object())
        {
            out.limitpea = j["LimitPEA"].get<LimitPEA>();
        }
    }
};

template<>
struct adl_serializer<IntelligentResponse>
{
    static void from_json(const json& j, IntelligentResponse& out)
    {
        out.intelligent = j.value("Intelligent", Intelligent());
        out.name = j.value("Name", "");
        out.ret = j.value("Ret", 0);
        out.sessionID = j.value("SessionID", "");
    }
};
}

using DeviceIntelligentAbilityResponse = Response<IntelligentResponse>;