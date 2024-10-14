#include "jlink_client.h"
#include "jlink_device.h"
#include "fmt/core.h"

int main()
{
    // developer params obtained from (open.jftech.com)
    std::string uuid = "e0534f3240274897821a126be19b6d46";
    std::string app_key = "0621ef206a1d4cafbe0c5545c3882ea8";
    std::string app_secret = "90f8bc17be2a425db6068c749dee4f5d";
    int movecard = 2;

    // dev_sn is device serial number
    std::string dev_sn = "";
    std::string dev_user_name = "";
    std::string dev_password = "";
    
    JLinkClient client(uuid, app_key, app_secret, movecard);
    JLinkDevice device(&client, dev_sn, dev_user_name, dev_password);
    
    auto resp_0 = device.deviceBind();
    auto resp_1 = device.getDeviceList();

    fmt::println("{}, {}, {}", resp_1.code, resp_1.msg, resp_1.data.size());

    auto resp_2 = device.deviceUnBind();

    return 0;
}