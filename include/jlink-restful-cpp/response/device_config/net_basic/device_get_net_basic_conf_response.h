/*
功能：获取网络基础配置响应体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=5636cc42d9254b2086431d356d523bfa&lang=zh
*/
#pragma once
#include "response/response.h"

class NetCommon
{
public:
    std::string gateway;
    std::string host_ip;
    std::string host_name;
    int http_port;
    std::string mac;
    int max_bps;
    std::string mon_mode;
    int ssl_port;
    std::string sub_mask;
    int tcp_max_conn;
    int tcp_port;
    std::string trans_ferplan;
    int udp_port;
    bool use_hs_downLoad;
};

class NetCommonResponse
{
public:
    std::string name;
    NetCommon net_common;
    int ret;
    std::string sessionID;
};

namespace nlohmann
{
template <>
struct adl_serializer<NetCommon>
{
    static void from_json(const json& j, NetCommon& out)
    {
        out.gateway = j.value("gateway", "");
        out.host_ip = j.value("hostip", "");
        out.host_name = j.value("hostname", "");
        out.http_port = j.value("httpport", 0);
        out.mac = j.value("mac", "");
        out.max_bps = j.value("maxbps", 0);
        out.mon_mode = j.value("monmode", "");
        out.ssl_port = j.value("sslport", 0);
        out.sub_mask = j.value("submask", "");
        out.tcp_max_conn = j.value("tcpmaxconn", 0);
        out.tcp_port = j.value("tcpport", 0);
        out.trans_ferplan = j.value("transferplan", "");
        out.udp_port = j.value("udpport", 0);
    }
};

template <>
struct adl_serializer<NetCommonResponse>
{
    static void from_json(const json& j, NetCommonResponse& out)
    {
        out.name = j.value("Name", "");
        out.net_common = j.value("NetWork.NetCommon", NetCommon());
        out.ret = j.value("Ret", 0);
        out.sessionID = j.value("SessionID", "");
    }
};

} // namespace nlohmann

using DeviceNetBasicConfResponse = Response<NetCommonResponse>;