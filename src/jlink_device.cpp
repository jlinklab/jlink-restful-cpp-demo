#include <assert.h>
#include "jlink_device.h"
#include "jlink_client.h"
#include "json/json.hpp"
#include "fmt/core.h"
#include "const.h"

using namespace nlohmann;

JLinkDevice::JLinkDevice(JLinkClient* client,
                         const std::string& dev_sn,
                         const std::string& dev_user_name,
                         const std::string& dev_password)
    : _client(client)
    , _dev_sn(dev_sn)
    , _dev_user_name(dev_user_name)
    , _dev_password(dev_password)
{
    assert(_client != nullptr);
}

JLinkDevice::~JLinkDevice() { }

DeviceBindResponse JLinkDevice::deviceBind(const std::string& type,
                                           const std::string& nickname,
                                           const std::string& ip,
                                           const std::string& port,
                                           bool isSubscription)

{
    json j;
    j["sn"] = _dev_sn;
    j["username"] = _dev_user_name;
    j["password"] = _dev_password;
    j["type"] = type;
    j["nickname"] = nickname;
    j["ip"] = ip;
    j["port"] = port;
    j["isSubscription"] = isSubscription;

    std::string url = fmt::format("{}{}", GWP_URL, DEV_BIND_URL);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceBindResponse response = j_resp;
    return response;
}

DeviceUnBindResponse JLinkDevice::deviceUnBind()
{
    json j;
    j["sn"] = _dev_sn;

    std::string url = fmt::format("{}{}{}", GWP_URL, DEV_UNBIND_URL, _dev_token);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceUnBindResponse response = j_resp;
    return response;
}

DeviceListResponse JLinkDevice::getDeviceList(int page, int limit)
{
    json j;
    j["page"] = page;
    j["limit"] = limit;

    std::string url = fmt::format("{}{}", GWP_URL, DEV_LIST_URL);
    std::string resp = _client->request(url, j.dump());

    json j_resp = json::parse(resp);
    DeviceListResponse response = j_resp;
    return response;
}
