#pragma once

#include <string>
#include "jlink_device.h"

class MqttConnectOptions
{
public:
    MqttConnectOptions(std::string userName, std::string passWord)
        : keep_alive(15)
        , clean_session(true)
        , retry_interval(2)
        , connect_timeout(10)
    {
        user_name = userName;
        password = passWord;
    }

public:
    std::string user_name; // 用户名，用户登录后获取到的用户id
    std::string password;  // 密码，用户登录后获取的token
    int keep_alive;        // 保活时间, 默认15s
    int clean_session;     // 是否清除会话, 默认清除
    int retry_interval;    // 重试间隔, 默认2s
    int connect_timeout;   // 连接超时, 默认10s
};