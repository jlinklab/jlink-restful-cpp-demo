/*
功能列表：https://docs.jftech.com/docs?menusId=54582398fd8d4248962354e92ac2e47a&siderId=0473d78bd2224c14a9d5dd5084ff6085&lang=zh
描述：开发者相关功能
*/
#include <assert.h>
#include "jlink_client.h"
#include "jlink_developer.h"
#include "json/json.hpp"
#include "fmt/core.h"
#include "const.h"
#include "utils.h"

using namespace nlohmann;

// 安全解析网络响应: 网络失败/非JSON响应时返回带错误码的对象，避免抛出异常
static json safeParse(const std::string& resp)
{
    try {
        json j = json::parse(resp);
        if (j.is_object()) {
            return j;
        }
    } catch (const std::exception& e) {
        fmt::println("parse response failed: {}", e.what());
    }
    return json{{"code", -1}, {"msg", "invalid response"}};
}

JLinkDeveloper::JLinkDeveloper(JLinkClient* client, DeveloperInfo& developerInfo)
    : _client(client)
{
    assert(_client != nullptr);
}

JLinkDeveloper::~JLinkDeveloper() { }

// 获取设备列表
DeviceListResponse JLinkDeveloper::getDeviceList(int page, int limit)
{
    json j;
    j["page"] = page;
    j["limit"] = limit;

    std::string url = fmt::format("{}{}", GWP_URL, DEV_LIST_URL);
    std::string resp = _client->request(url, j.dump());

    json j_resp = safeParse(resp);
    DeviceListResponse response = j_resp;
    return response;
}

SendCaptchaResponse JLinkDeveloper::sendCaptcha(const SendCaptcha& sendCaptcha)
{
    std::string url = fmt::format("{}/{}", AMS_URL, DEVELOP_SEND_CAPTCHA_URL);
    std::string resp = _client->requestAMS(url, sendCaptcha.to_string());

    json j_resp = safeParse(resp);
    SendCaptchaResponse response = j_resp;
    return response;
}

PhoneRegResponse JLinkDeveloper::regWithPhoneCode(const PhoneRegInfo& reg_info)
{
    std::string url = fmt::format("{}/{}", AMS_URL, DEVELOP_USER_REG_PHONE_URL);
    std::string resp = _client->requestAMS(url, reg_info.to_string());

    json j_resp = safeParse(resp);
    PhoneRegResponse response = j_resp;
    return response;
}

UserLoginResponse JLinkDeveloper::userLogin(const UserLoginInfo& login_info)
{
    std::string url = fmt::format("{}/{}", AMS_URL, DEVELOP_USER_LOGIN_URL);

    std::string resp = _client->userLogin(url, login_info);

    json j_resp = safeParse(resp);
    UserLoginResponse response = j_resp;
    _access_token = response.data.access_token;

    return response;
}

GetAMSUserInfoResponse JLinkDeveloper::userInfo()
{
    std::string url = fmt::format("{}/{}", AMS_URL, DEVELOP_USER_INFO_URL);
    std::string resp = _client->requestAMS_userInfo(url, _access_token);

    json j_resp = safeParse(resp);
    std::cout << j_resp.dump() << std::endl;
    GetAMSUserInfoResponse response = j_resp;
    _userid = response.data.userId;

    return response;
}

ModifyPassResponse JLinkDeveloper::modifyPass(const ModifyPass& modify_info)
{
    std::string url = fmt::format("{}/{}", AMS_URL, DEVELOP_MODIFY_PASS_URL);
    std::string resp = _client->requestAMS(url, modify_info.to_string());

    json j_resp = safeParse(resp);
    ModifyPassResponse response = j_resp;

    return response;
}

UserModifyPassUnLoginResponse JLinkDeveloper::modifyPassUnlogin(const ModifyPass_UnLogin& modify_info)
{
    std::string url = fmt::format("{}/{}", AMS_URL, DEVELOP_MODIFY_PASS_UNLOGIN_URL);
    std::string resp = _client->requestAMS(url, modify_info.to_string());

    json j_resp = safeParse(resp);
    UserModifyPassUnLoginResponse response = j_resp;
    return response;
}