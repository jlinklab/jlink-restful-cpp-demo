#include <fstream>
#include "fmt/core.h"
#include "request/request.h"
#include "mqttmessage.h"
#include "demo.h"

int main()
{
#ifdef WIN32
    system("chcp 65001");
#endif
    Params params;
    getParams(params);

    DeveloperInfo developerInfo;
    developerInfo.app_key = params._app_key;
    developerInfo.app_secret = params._app_secret;
    developerInfo.movecard = params._movecard;
    developerInfo.uuid = params._uuid;

    JLinkClient client(developerInfo);
    JLinkDevice device(&client, params._dev_sn, params._dev_user_name, params._dev_password);
    JLinkDeveloper developer(&client, developerInfo);
    JLinkMqttSubscriber mqttsubscriber(developerInfo);

    mainMenu(&client, &device, &developer);


#if 0
    // mqtt订阅
    device.getDeviceToken();
    device.deviceLogin();

    UserLoginInfo userLoginInfo;
    userLoginInfo.account = "********";
    userLoginInfo.password = "*********";
    auto resp_0 = developer.userLogin(userLoginInfo);
    auto resp_1 = developer.userInfo();

    MyMqttListener mqttListener;
    MqttConnectOptions connectOptions(resp_1.data.userId, resp_0.data.access_token);

    mqttsubscriber.setCallback(&mqttListener);
    while (true) {
        if (!mqttsubscriber.connect("mqtt://jfmq-v2.xmcsrv.net:1883", connectOptions)) {
            std::cout << "连接成功" << std::endl;

            mqttsubscriber.subscribeDeviceStatus_client(device._dev_token, 0);
            mqttsubscriber.deviceAlarmInfo_client(device._dev_token, 0);
            //mqttsubscriber.devicePassThrough_client(device._dev_token, 0);
            //mqttsubscriber.deviceInfoReport_client(device._dev_token, 0);
            break;

        } else {
            std::cout << "连接失败，尝试重新连接" << std::endl;
        }
    }

    while (true) {
        Sleep(1000);
    }

#endif

    return 0;
}