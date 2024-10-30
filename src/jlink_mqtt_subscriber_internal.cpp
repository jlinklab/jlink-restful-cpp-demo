#include "jlink_mqtt_subscriber_internal.h"
#include "fmt/core.h"
#include "utils.h"
#include "openssl/rand.h"

void MQTTClient_connectionLost0(void* context, char* cause)
{
    JLinkMqttSubscriberInternal* sub = (JLinkMqttSubscriberInternal*)context;
    if (sub) {
        if (cause) {
            sub->onConnectLoss(cause);
        }
    }
}

int MQTTClient_messageArrived0(void* context, char* topicName, int topicLen, MQTTClient_message* message)
{
    JLinkMqttSubscriberInternal* sub = (JLinkMqttSubscriberInternal*)context;
    if (sub) {
        std::string topic = topicName;
        if (topicLen > 0) {
            topic = std::string(topicName, topicLen);
        }
        sub->onMessageArrive(topic, message);
    }

    return 1;
}

JLinkMqttSubscriberInternal::JLinkMqttSubscriberInternal(const DeveloperInfo& develop_info)
    : _client(nullptr)
    , _develop_info(develop_info)
    , _listener(nullptr)
{
}

JLinkMqttSubscriberInternal::~JLinkMqttSubscriberInternal() { }

int JLinkMqttSubscriberInternal::setCallback(MqttListener* listener)
{
    _listener = listener;
    return 0;
}

int JLinkMqttSubscriberInternal::connect(const std::string& server_uri, const MqttConnectOptions& options)
{
    unsigned char rand[4] = {};
    RAND_bytes(rand, 4);

    std::string client_id =
        fmt::format("{}:{:02x}{:02x}{:02x}{:02x}", _develop_info.uuid, rand[0], rand[1], rand[2], rand[3]);
    fmt::println("client_id: {}", client_id);

    int n_ret =
        MQTTClient_create(&_client, server_uri.c_str(), client_id.c_str(), MQTTCLIENT_PERSISTENCE_NONE, nullptr);
    if (n_ret != MQTTCLIENT_SUCCESS) {
        fmt::println("mqtt client create failed");
        return -1;
    }

    int ret = MQTTClient_setCallbacks(_client, this, MQTTClient_connectionLost0, MQTTClient_messageArrived0, NULL);

    MQTTClient_connectOptions opt = MQTTClient_connectOptions_initializer;
    opt.username = options.user_name.c_str();
    opt.password = options.password.c_str();
    opt.keepAliveInterval = options.keep_alive;
    opt.cleansession = options.clean_session;
    opt.retryInterval = options.retry_interval;
    opt.connectTimeout = options.connect_timeout;

    n_ret = MQTTClient_connect(_client, &opt);
    if (n_ret != MQTTCLIENT_SUCCESS) {
        const char* str = MQTTClient_strerror(n_ret);
        fmt::println("mqtt client connect failed");
        return -2;
    }

    return 0;
}

int JLinkMqttSubscriberInternal::subscribeDeviceStatus_server(const std::string& dev_token, int qos)
{
    if (!_client)
        return -11;

    std::string topic = fmt::format("{}/device/{}/status", _develop_info.uuid, dev_token);
    int n_ret = MQTTClient_subscribe(_client, topic.c_str(), qos);
    if (n_ret != MQTTCLIENT_SUCCESS) {
        fmt::println("mqtt server subscribe device status failed");
        n_ret = -3;
    }

    return n_ret;
}

int JLinkMqttSubscriberInternal::unsubscribeDeviceStatus_server(const std::string& dev_token, int qos)
{
    if (!_client)
        return -11;

    std::string topic = fmt::format("{}/device/{}/status", _develop_info.uuid, dev_token);
    MQTTClient_unsubscribe(_client, topic.c_str());

    return 0;
}

int JLinkMqttSubscriberInternal::subscribeDeviceStatus_client(const std::string& dev_token, int qos)
{
    if (!_client)
        return -11;

    std::string topic = fmt::format("{}/device/{}/status", _develop_info.app_key, dev_token);
    int n_ret = MQTTClient_subscribe(_client, topic.c_str(), qos);
    if (n_ret != MQTTCLIENT_SUCCESS) {
        fmt::println("mqtt client subscribe device status failed");
        n_ret = -3;
    }

    return n_ret;
}

int JLinkMqttSubscriberInternal::unsubscribeDeviceStatus_client(const std::string& dev_token, int qos)
{
    if (!_client)
        return -11;

    std::string topic = fmt::format("{}/device/{}/status", _develop_info.app_key, dev_token);
    MQTTClient_unsubscribe(_client, topic.c_str());

    return 0;
}

int JLinkMqttSubscriberInternal::subscribeDeviceStatus_many(int qos)
{
    if (!_client)
        return -11;

    std::string topic = fmt::format("{}/device/+/status", _develop_info.app_key);
    int n_ret = MQTTClient_subscribe(_client, topic.c_str(), qos);
    if (n_ret != MQTTCLIENT_SUCCESS) {
        fmt::println("mqtt client subscribe device status failed");
        n_ret = -3;
    }

    return 0;
}

int JLinkMqttSubscriberInternal::unsubscribeDeviceStatus_many(int qos)
{
    if (!_client)
        return -11;

    std::string topic = fmt::format("{}/device/+/status", _develop_info.app_key);
    MQTTClient_unsubscribe(_client, topic.c_str());

    return 0;
}

int JLinkMqttSubscriberInternal::deviceInfoReport_server(const std::string& dev_token, int qos)
{
    if (!_client)
        return -11;

    std::string topic = fmt::format("{}/device/{}", _develop_info.uuid, dev_token);
    int n_ret = MQTTClient_subscribe(_client, topic.c_str(), qos);
    if (n_ret != MQTTCLIENT_SUCCESS) {
        fmt::println("mqtt client subscribe device status failed");
        n_ret = -3;
    }

    return n_ret;
}

int JLinkMqttSubscriberInternal::undeviceInfoReport_server(const std::string& dev_token, int qos)
{
    if (!_client)
        return -11;

    std::string topic = fmt::format("{}/device/{}", _develop_info.uuid, dev_token);
    MQTTClient_unsubscribe(_client, topic.c_str());

    return 0;
}

int JLinkMqttSubscriberInternal::deviceInfoReport_many(int qos)
{
    if (!_client)
        return -11;

    std::string topic = fmt::format("{}/device/+", _develop_info.uuid);
    int n_ret = MQTTClient_subscribe(_client, topic.c_str(), qos);
    if (n_ret != MQTTCLIENT_SUCCESS) {
        fmt::println("mqtt client subscribe device status failed");
        n_ret = -3;
    }

    return 0;
}

int JLinkMqttSubscriberInternal::undeviceInfoReport_many(int qos)
{
    if (!_client)
        return -11;

    std::string topic = fmt::format("{}/device/+", _develop_info.uuid);
    MQTTClient_unsubscribe(_client, topic.c_str());

    return 0;
}

int JLinkMqttSubscriberInternal::deviceAlarmInfo_server(const std::string& dev_token, int qos)
{
    if (!_client)
        return -11;

    std::string topic = fmt::format("{}/device/{}/alarmEvent", _develop_info.uuid, dev_token);
    int n_ret = MQTTClient_subscribe(_client, topic.c_str(), qos);
    if (n_ret != MQTTCLIENT_SUCCESS) {
        fmt::println("mqtt server alarmInfo failed");
        n_ret = -3;
    }

    return n_ret;
}

int JLinkMqttSubscriberInternal::undeviceAlarmInfo_server(const std::string& dev_token, int qos)
{
    if (!_client)
        return -11;

    std::string topic = fmt::format("{}/device/{}/alarmEvent", _develop_info.uuid, dev_token);
    MQTTClient_unsubscribe(_client, topic.c_str());

    return 0;
}

int JLinkMqttSubscriberInternal::deviceAlarmInfo_client(const std::string& dev_token, int qos)
{
    if (!_client)
        return -11;

    std::string topic = fmt::format("{}/device/{}/alarmEvent", _develop_info.app_key, dev_token);
    int n_ret = MQTTClient_subscribe(_client, topic.c_str(), qos);
    if (n_ret != MQTTCLIENT_SUCCESS) {
        fmt::println("mqtt client alarmInfo failed");
        n_ret = -3;
    }

    return n_ret;
}

int JLinkMqttSubscriberInternal::undeviceAlarmInfo_client(const std::string& dev_token, int qos)
{
    if (!_client)
        return -11;

    std::string topic = fmt::format("{}/device/{}/alarmEvent", _develop_info.app_key, dev_token);
    MQTTClient_unsubscribe(_client, topic.c_str());

    return 0;
}

int JLinkMqttSubscriberInternal::deviceAlarmInfo_many(int qos)
{
    if (!_client)
        return -11;

    std::string topic = fmt::format("{}/device/+/alarmEvent", _develop_info.uuid);
    int n_ret = MQTTClient_subscribe(_client, topic.c_str(), qos);
    if (n_ret != MQTTCLIENT_SUCCESS) {
        fmt::println("mqtt client subscribe device status failed");
        n_ret = -3;
    }

    return 0;
}

int JLinkMqttSubscriberInternal::undeviceAlarmInfo_many(int qos)
{
    if (!_client)
        return -11;

    std::string topic = fmt::format("{}/device/+/alarmEvent", _develop_info.uuid);
    MQTTClient_unsubscribe(_client, topic.c_str());

    return 0;
}

int JLinkMqttSubscriberInternal::devicePassThrough_server(const std::string& dev_token, int qos)
{
    if (!_client)
        return -11;

    std::string topic = fmt::format("{}/device/{}/req_dispatch", _develop_info.uuid, dev_token);
    int n_ret = MQTTClient_subscribe(_client, topic.c_str(), qos);
    if (n_ret != MQTTCLIENT_SUCCESS) {
        fmt::println("mqtt client pass through failed");
        n_ret = -3;
    }

    return n_ret;
}

int JLinkMqttSubscriberInternal::undevicePassThrough_server(const std::string& dev_token, int qos)
{
    if (!_client)
        return -11;

    std::string topic = fmt::format("{}/device/{}/req_dispatch", _develop_info.uuid, dev_token);
    MQTTClient_unsubscribe(_client, topic.c_str());

    return 0;
}

int JLinkMqttSubscriberInternal::devicePassThrough_many(int qos)
{
    if (!_client)
        return -11;

    std::string topic = fmt::format("{}/device/+/req_dispatch", _develop_info.uuid);
    int n_ret = MQTTClient_subscribe(_client, topic.c_str(), qos);
    if (n_ret != MQTTCLIENT_SUCCESS) {
        fmt::println("mqtt client pass through failed");
        n_ret = -3;
    }

    return 0;
}

int JLinkMqttSubscriberInternal::undevicePassThrough_many(int qos)
{
    if (!_client)
        return -11;

    std::string topic = fmt::format("{}/device/+/req_dispatch", _develop_info.uuid);
    MQTTClient_unsubscribe(_client, topic.c_str());

    return 0;
}

int JLinkMqttSubscriberInternal::onConnectLoss(const std::string& reason)
{
    if (_listener) {
        _listener->onConnectLost(reason);
    }

    return 0;
}

int JLinkMqttSubscriberInternal::onMessageArrive(const std::string& topic, MQTTClient_message* message)
{
    std::string data((char*)message->payload, message->payloadlen);
    std::cout << data << std::endl;

    if (!_listener || !json::accept(data)) {
        return 0;
    }

    json j = json::parse(data);

    size_t pos = topic.rfind("/");
    if (pos != std::string::npos && topic.substr(pos + 1) == "status") {
        DeviceStatusMsg msg = j;
        return _listener->onDeviceStatusMsg(msg);
    } else if (pos != std::string::npos && topic.substr(pos + 1) == "alarmEvent") {
        AlarmInfoMsg msg = j;
        return _listener->onAlarmInfoMsg(msg);
    } else if (pos != std::string::npos && topic.substr(pos + 1) == "req_dispatch") {
        PassThroughMsg msg = j;
        return _listener->onPassThroughMsg(msg);
    }

    return 0;
}
