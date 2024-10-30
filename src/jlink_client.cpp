/*
描述：客户端相关功能
功能：使用libcurl库发送请求
*/
#include "jlink_client.h"
#include "fmt/core.h"
#include "curl/curl.h"
#include "utils.h"

JLinkClient::JLinkClient(const DeveloperInfo& info)
    : _developer_info(info)
{
}

JLinkClient::~JLinkClient() { }

size_t writeCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string JLinkClient::request(const std::string& url, const std::string& param)
{
    std::string response;
    CURL* curl = curl_easy_init();

    std::string ts = utils::getTimeStamp();
    std::string uuid = fmt::format("uuid: {}", _developer_info.uuid);
    std::string app_key = fmt::format("appKey: {}", _developer_info.app_key);
    std::string timestamp = fmt::format("timeMillis: {}", ts);
    std::string sig_value = utils::getSignature(_developer_info, ts);
    std::string signature = fmt::format("signature: {}", sig_value);

    struct curl_slist* headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, uuid.c_str());
    headers = curl_slist_append(headers, app_key.c_str());
    headers = curl_slist_append(headers, timestamp.c_str());
    headers = curl_slist_append(headers, signature.c_str());

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_POST, 1);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, param.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, param.length());
    //curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); // 重定向
    //curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L); // curl日志

    CURLcode code = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    if (code != CURLE_OK) {
        std::string err_msg = fmt::format("curl_easy_perform() failed: {}", curl_easy_strerror(code));
        fmt::println("error: {}", err_msg);
    }

    fmt::println("resp: {}", response);

    return response;
}

std::string JLinkClient::requestAMS(const std::string& in_url, const std::string& param)
{
    std::string response;
    CURL* curl = curl_easy_init();

    std::string uuid = fmt::format("uuid: {}", _developer_info.uuid);
    std::string app_key = fmt::format("appKey: {}", _developer_info.app_key);
    std::string url = in_url;
    std::string authorization = "";
    if (in_url.find(".rs") == std::string::npos) {
        std::string ts = utils::getTimeStamp();
        std::string sig = utils::getSignature(_developer_info, ts);
        url = fmt::format("{}/{}/{}.rs", in_url, ts, sig);
    }

    struct curl_slist* headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");
    headers = curl_slist_append(headers, uuid.c_str());
    headers = curl_slist_append(headers, app_key.c_str());

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_POST, 1);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, param.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, param.length());
    //curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); // 重定向
    //curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L); // curl日志

    fmt::println("url: {}", url);
    fmt::println("req: {}", param);
    CURLcode code = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    if (code != CURLE_OK) {
        std::string err_msg = fmt::format("curl_easy_perform() failed: {}", curl_easy_strerror(code));
        fmt::println("error: {}", err_msg);
    } else {
        // url解码
        response = curl_unescape(response.c_str(), (int)response.length());
    }

    fmt::println("resp: {}", response);

    return response;
}

std::string JLinkClient::requestAMS_userInfo(const std::string& in_url, const std::string& access_token)
{
    const std::string& param = std::string("");
    std::string response;
    CURL* curl = curl_easy_init();

    std::string uuid = fmt::format("uuid: {}", _developer_info.uuid);
    std::string app_key = fmt::format("appKey: {}", _developer_info.app_key);
    std::string authorization = fmt::format("Authorization: {}", access_token);
    std::string url = in_url;

    if (in_url.find(".rs") == std::string::npos) {
        std::string ts = utils::getTimeStamp();
        std::string sig = utils::getSignature(_developer_info, ts);
        url = fmt::format("{}/{}/{}.rs", in_url, ts, sig);
    }

    struct curl_slist* headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");
    headers = curl_slist_append(headers, uuid.c_str());
    headers = curl_slist_append(headers, app_key.c_str());
    headers = curl_slist_append(headers, authorization.c_str());

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_POST, 1);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, param.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, param.length());

    fmt::println("url: {}", url);

    CURLcode code = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    if (code != CURLE_OK) {
        std::string err_msg = fmt::format("curl_easy_perform() failed: {}", curl_easy_strerror(code));
        fmt::println("error: {}", err_msg);
    } else {
        // url解码
        response = curl_unescape(response.c_str(), (int)response.length());
    }

    fmt::println("resp: {}", response);

    return response;
}

std::string JLinkClient::userLogin(const std::string& in_url, const UserLoginInfo& login_info)
{
    std::string ts = utils::getTimeStamp();
    std::string sig = utils::getSignature(_developer_info, ts);
    std::string data = utils::AESEncode("test", _developer_info, ts);
    // fmt::println("enc: {}", data);
    std::string account_aes = utils::AESEncode(login_info.account, _developer_info, ts);
    std::string password_aes = utils::AESEncode(login_info.password, _developer_info, ts);

    std::string param = fmt::format("account={}&pass={}", account_aes, password_aes);
    std::string url = fmt::format("{}/{}/{}.rs", in_url, ts, sig);
    return requestAMS(url, param);
}
