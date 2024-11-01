/*
功能：设置网络基础配置请求体封装
描述：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=e1e27b8be1724065897590046789cb54&lang=zh
*/
#pragma once
#include "request/request.h"

class NetCommonRequest {
public:
    std::string GateWay;
    std::string HostIP;
    std::string HostName;
    int HttpPort;
    std::string MAC;
    int MaxBps;
    std::string MonMode;
    int SSLPort;
    std::string Submask;
    int TCPMaxConn;
    int TCPPort;
    std::string TransferPlan;
    int UDPPort;
    bool UseHSDownLoad;

    NetCommonRequest()
        : HttpPort(0)
        , MaxBps(0)
        , SSLPort(0)
        , TCPMaxConn(0)
        , TCPPort(0)
        , UDPPort(0)
        , UseHSDownLoad(false)
    { }
};

namespace nlohmann {
template <>
struct adl_serializer<NetCommonRequest> {
    static void to_json(json& j, const NetCommonRequest& net) {
        j = json{
            {"GateWay", net.GateWay},
            {"HostIP", net.HostIP},
            {"HostName", net.HostName},
            {"HttpPort", net.HttpPort},
            {"MAC", net.MAC},
            {"MaxBps", net.MaxBps},
            {"MonMode", net.MonMode},
            {"SSLPort", net.SSLPort},
            {"Submask", net.Submask},
            {"TCPMaxConn", net.TCPMaxConn},
            {"TCPPort", net.TCPPort},
            {"TransferPlan", net.TransferPlan},
            {"UDPPort", net.UDPPort},
            {"UseHSDownLoad", net.UseHSDownLoad}
        };
    }
};
}