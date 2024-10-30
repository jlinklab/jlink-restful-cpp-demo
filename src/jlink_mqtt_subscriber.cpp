#include "jlink_mqtt_subscriber.h"
#include "jlink_mqtt_subscriber_internal.h"
#include "fmt/core.h"
#include "utils.h"
#include "openssl/rand.h"

JLinkMqttSubscriber::JLinkMqttSubscriber(const DeveloperInfo& develop_info)
{
    _impl = new JLinkMqttSubscriberInternal(develop_info);
}

JLinkMqttSubscriber::~JLinkMqttSubscriber()
{
    delete _impl;
}

int JLinkMqttSubscriber::setCallback(MqttListener* listener)
{
    return _impl->setCallback(listener);
}

int JLinkMqttSubscriber::connect(const std::string& server_uri, const MqttConnectOptions& options)
{
    return _impl->connect(server_uri, options);
}

int JLinkMqttSubscriber::subscribeDeviceStatus_server(const std::string& dev_token, int qos)
{
    return _impl->subscribeDeviceStatus_server(dev_token, qos);
}

int JLinkMqttSubscriber::unsubscribeDeviceStatus_server(const std::string& dev_token, int qos)
{
    return _impl->unsubscribeDeviceStatus_server(dev_token, qos);
}

int JLinkMqttSubscriber::subscribeDeviceStatus_client(const std::string& dev_token, int qos)
{
    return _impl->subscribeDeviceStatus_client(dev_token, qos);
}

int JLinkMqttSubscriber::unsubscribeDeviceStatus_client(const std::string& dev_token, int qos)
{
    return _impl->unsubscribeDeviceStatus_client(dev_token, qos);
}

int JLinkMqttSubscriber::subscribeDeviceStatus_many(int qos)
{
    return _impl->subscribeDeviceStatus_many(qos);
}

int JLinkMqttSubscriber::unsubscribeDeviceStatus_many(int qos)
{
    return _impl->unsubscribeDeviceStatus_many(qos);
}

int JLinkMqttSubscriber::deviceInfoReport_server(const std::string& dev_token, int qos)
{
    return _impl->deviceInfoReport_server(dev_token, qos);
}

int JLinkMqttSubscriber::undeviceInfoReport_server(const std::string& dev_token, int qos)
{
    return _impl->undeviceInfoReport_server(dev_token, qos);
}

int JLinkMqttSubscriber::deviceInfoReport_many(int qos)
{
    return _impl->deviceInfoReport_many(qos);
}

int JLinkMqttSubscriber::undeviceInfoReport_many(int qos)
{
    return _impl->undeviceInfoReport_many(qos);
}

int JLinkMqttSubscriber::deviceAlarmInfo_server(const std::string& dev_token, int qos)
{
    return _impl->deviceAlarmInfo_server(dev_token, qos);
}

int JLinkMqttSubscriber::undeviceAlarmInfo_server(const std::string& dev_token, int qos)
{
    return _impl->undeviceAlarmInfo_server(dev_token, qos);
}

int JLinkMqttSubscriber::deviceAlarmInfo_client(const std::string& dev_token, int qos)
{
    return _impl->deviceAlarmInfo_client(dev_token, qos);
}

int JLinkMqttSubscriber::undeviceAlarmInfo_client(const std::string& dev_token, int qos)
{
    return _impl->undeviceAlarmInfo_client(dev_token, qos);
}

int JLinkMqttSubscriber::deviceAlarmInfo_many(int qos)
{
    return _impl->deviceAlarmInfo_many(qos);
}

int JLinkMqttSubscriber::undeviceAlarmInfo_many(int qos)
{
    return _impl->undeviceAlarmInfo_many(qos);
}

int JLinkMqttSubscriber::devicePassThrough_server(const std::string& dev_token, int qos)
{
    return _impl->devicePassThrough_server(dev_token, qos);
}

int JLinkMqttSubscriber::undevicePassThrough_server(const std::string& dev_token, int qos)
{
    return _impl->undevicePassThrough_server(dev_token, qos);
}

int JLinkMqttSubscriber::devicePassThrough_many(int qos)
{
    return _impl->devicePassThrough_many(qos);
}

int JLinkMqttSubscriber::undevicePassThrough_many(int qos)
{
    return _impl->undevicePassThrough_many(qos);
}