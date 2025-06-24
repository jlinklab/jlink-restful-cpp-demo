/*
功能：对讲音频属性能力响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=51e1aa807aaf10dc82c251f0b73ed116&lang=zh
*/
#pragma once
#include "response/response.h"

// 之前定义的结构体复用
class AudioPram
{
public:
    std::string enc;
    std::vector<int> sb;
    std::vector<int> sr;
};

class VideoResPram
{
public:
    int fps;
    int h;
    int w;
};

class VideoPram
{
public:
    std::string enc;
    std::vector<VideoResPram> res;
};

class DecoderPram
{
public:
    std::vector<AudioPram> audio;
    std::vector<VideoPram> video;
};

class DecoderPramResponse
{
public:
    DecoderPram decoder_pram;
};

namespace nlohmann
{
template <>
struct adl_serializer<AudioPram>
{
    static void from_json(const json& j, AudioPram& out)
    {
        out.enc = j.value("Enc", "");
        out.sb = j.value("SB", std::vector<int>());
        out.sr = j.value("SR", std::vector<int>());
    }
};

template <>
struct adl_serializer<VideoResPram>
{
    static void from_json(const json& j, VideoResPram& out)
    {
        out.fps = j.value("FPS", 0);
        out.h = j.value("H", 0);
        out.w = j.value("W", 0);
    }
};

template <>
struct adl_serializer<VideoPram>
{
    static void from_json(const json& j, VideoPram& out)
    {
        out.enc = j.value("Enc", "");
        out.res = j.value("Res", std::vector<VideoResPram>());
    }
};

template <>
struct adl_serializer<DecoderPram>
{
    static void from_json(const json& j, DecoderPram& out)
    {
        out.audio = j.value("Audio", std::vector<AudioPram>());
        out.video = j.value("Video", std::vector<VideoPram>());
    }
};

template <>
struct adl_serializer<DecoderPramResponse>
{
    static void from_json(const json& j, DecoderPramResponse& out)
    {
        out.decoder_pram = j.value("DecoderPram", DecoderPram());
    }
};
} // namespace nlohmann

using DecoderPramAblity = Response<DecoderPramResponse>;