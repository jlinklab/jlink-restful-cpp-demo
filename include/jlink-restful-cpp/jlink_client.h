#pragma once

#include <string>
#include "response/response.h"
#include "request/user_account/developer_userlogin_request.h"
#include "developer_info.h"

class JLinkClient
{
public:
    JLinkClient(const DeveloperInfo& info);
    ~JLinkClient();

    // json格式请求
    std::string request(const std::string& url, const std::string& param);

    // 向AMS请求, 表单格式
    std::string requestAMS(const std::string& url, const std::string& param);

    // 用户登录
    std::string userLogin(const std::string& in_url, const UserLoginInfo& login_info);

    // 获取用户信息
    std::string requestAMS_userInfo(const std::string& in_url, const std::string& param);

private:
    DeveloperInfo _developer_info;
};