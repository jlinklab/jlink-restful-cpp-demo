#pragma once

#include "developer_info.h"
#include "mqtt_conn_options.h"
#include "mqtt_listener.h"
#include "MQTTClient.h"

class JLinkMqttSubscriberInternal
{
public:
    JLinkMqttSubscriberInternal(const DeveloperInfo& develop_info);
    ~JLinkMqttSubscriberInternal();
    
    // 设置回调对象, 不负责释放
    int setCallback(MqttListener* listener);
    
    // 连接(同步)
    int connect(const std::string& server_uri, const MqttConnectOptions& options);
    
    // 订阅设备状态信息(服务端接入用)
    int subscribeDeviceStatus_server(const std::string& dev_token, int qos);

    // 取消订阅设备状态信息(服务端接入用)
    int unsubscribeDeviceStatus_server(const std::string& dev_token, int qos);

    // 订阅设备状态信息(客户端接入用)
    int subscribeDeviceStatus_client(const std::string& dev_token, int qos);

    // 取消订阅设备状态信息(客户端接入用)
    int unsubscribeDeviceStatus_client(const std::string& dev_token, int qos);

    // 批量订阅设备状态信息
    int subscribeDeviceStatus_many(int qos);

    // 取消批量订阅设备状态信息
    int unsubscribeDeviceStatus_many(int qos);

    // 设备信息上报(服务端接入用)
    int deviceInfoReport_server(const std::string& dev_token, int qos);

    // 取消设备信息上报(服务端接入用)
    int undeviceInfoReport_server(const std::string& dev_token, int qos);

    // 批量设备信息上报(服务端接入用)
    int deviceInfoReport_many(int qos);

    // 批量取消设备信息上报(服务端接入用)
    int undeviceInfoReport_many(int qos);

    // 设备告警消息通知(服务端接入用)
    int deviceAlarmInfo_server(const std::string& dev_token, int qos);

    // 设备告警消息通知(服务端接入用)
    int undeviceAlarmInfo_server(const std::string& dev_token, int qos);

    // 设备告警消息通知(客户端接入用)
    int deviceAlarmInfo_client(const std::string& dev_token, int qos);

    // 设备告警消息通知(客户端接入用)
    int undeviceAlarmInfo_client(const std::string& dev_token, int qos);

    // 批量订阅透传消息通知
    int devicePassThrough_many(int qos);

    // 取消批量订阅透传消息通知
    int undevicePassThrough_many(int qos);

    // 订阅透传消息通知
    int devicePassThrough_server(const std::string& dev_token, int qos);

    // 取消订阅透传消息通知
    int undevicePassThrough_server(const std::string& dev_token, int qos);

    // 批量订阅透传消息通知
    int deviceAlarmInfo_many(int qos);

    // 取消批量订阅透传消息通知
    int undeviceAlarmInfo_many(int qos);

    // 连接丢失
    int onConnectLoss(const std::string& reason);
    
    // 消息来了
    int onMessageArrive(const std::string& topic, MQTTClient_message* message);
    
private:
    MQTTClient _client;
    DeveloperInfo _develop_info;
    MqttListener* _listener;
};