#pragma once

#include <string>
#include "response/response.h"
#include "request/request.h"

class JLinkClient;

class JLinkDeveloper
{
public:
    JLinkDeveloper(JLinkClient* client, DeveloperInfo& developerInfo);

    ~JLinkDeveloper();

    // 获取设备列表
    DeviceListResponse getDeviceList(int page = 1, int limit = 100);

    // 发送短信验证码
    SendCaptchaResponse sendCaptcha(const SendCaptcha& sendCaptcha);

    // 手机用户注册
    PhoneRegResponse regWithPhoneCode(const PhoneRegInfo& reg_info);

    // 用户登录
    UserLoginResponse userLogin(const UserLoginInfo& login_info);

    // 获取用户信息
    GetAMSUserInfoResponse userInfo();
    
    // 手机短信修改密码(需先登录)
    ModifyPassResponse modifyPass(const ModifyPass& modify_info);

    // 修改密码(无需登录)
    UserModifyPassUnLoginResponse modifyPassUnlogin(const ModifyPass_UnLogin& modify_info);

private:
    JLinkClient* _client;

    std::string _access_token;
    std::string _userid;
};
