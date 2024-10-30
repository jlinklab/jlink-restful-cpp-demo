/*
功能：对讲音频属性能力响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=51e1aa807aaf10dc82c251f0b73ed116&lang=zh
*/
#pragma once
#include "response/response.h"

class TalkAudioFormat
{
public:
    int bitrate;
    std::vector<std::string> encode_type;
    int sample_type;
    int sample_rate;
};

class TalkAudioFormatResponse
{
public:
    std::string name;
    int ret;
    std::string sessionID;
    std::vector<TalkAudioFormat> talk_audio_format;
};

namespace nlohmann
{
template<>
struct adl_serializer<TalkAudioFormat>
{
    static void from_json(const json& j, TalkAudioFormat& out)
    {
        out.bitrate = j.value("BitRate", 0);
        out.encode_type = j.value("EncodeType", std::vector<std::string>());
        out.sample_rate = j.value("SampleBit", 0);
        out.sample_type = j.value("SampleRate", 0);
    }
};

template<>
struct adl_serializer<TalkAudioFormatResponse>
{
    static void from_json(const json& j, TalkAudioFormatResponse& out)
    {
        out.name = j.value("Name", "");
        out.ret = j.value("Ret", 0);
        out.sessionID = j.value("SessionID", "");
        out.talk_audio_format = j.value("TalkAudioFormat", std::vector<TalkAudioFormat>());
    }
};
}

using DeviceTalkAudioAblity = Response<TalkAudioFormatResponse>;