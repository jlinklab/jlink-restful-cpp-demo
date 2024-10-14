#pragma once

#include <string>
#include "response.h"

class JLinkClient;
class JLinkDevice
{
public:
    JLinkDevice(JLinkClient* client, 
                const std::string& dev_sn, 
                const std::string& dev_user_name = "", 
                const std::string& dev_password = "");
    
    ~JLinkDevice();
    
    // 设备绑定
    DeviceBindResponse deviceBind(const std::string& type = "",
                                  const std::string& nickname = "", 
                                  const std::string& ip = "",
                                  const std::string& port = "",
                                  bool isSubscription = false);
    
    // 设备解绑
    DeviceUnBindResponse deviceUnBind();
    
    // 获取设备列表
    DeviceListResponse getDeviceList(int page = 1, int limit = 100);
    

private:
    JLinkClient* _client;
    std::string _dev_sn;
    std::string _dev_user_name;
    std::string _dev_password;
    std::string _dev_token;
};