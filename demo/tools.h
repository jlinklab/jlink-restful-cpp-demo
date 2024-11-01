#pragma once
#include <string>
#include "jlink_client.h"
#include "jlink_device.h"
#include "jlink_developer.h"
#include "jlink_mqtt_subscriber.h"
#include "fmt/core.h"

/*
说明：
开发者参数获取自 (open.jftech.com)
dev_sn 是设备序列号
获取到的开发者参数和设备参数填入config.ini文件中
*/
typedef struct Params
{
    std::string _uuid;
    std::string _app_key;
    std::string _app_secret;
    int _movecard;
    std::string _dev_sn;
    std::string _dev_user_name;
    std::string _dev_password;
} Params;

void getParams(Params& params);