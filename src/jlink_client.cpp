#include "jlink_client.h"
#include "fmt/core.h"
#include "curl/curl.h"
#include "utils.h"

JLinkClient::JLinkClient(const std::string& uuid,
                         const std::string& app_key,
                         const std::string& app_secret,
                         int movecard)
    : _uuid(uuid)
    , _app_key(app_key)
    , _app_secret(app_secret)
    , _movecard(movecard)
{
}

JLinkClient::~JLinkClient() { }

size_t writeCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    // Response* response = (Response*)userp;
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string JLinkClient::request(const std::string& url, const std::string& param)
{
    std::string response;
    CURL* curl = curl_easy_init();
    // if (!curl) {
    //     cerr << "Failed to initialize CURL" << endl;
    //     return "";
    // }

    std::string uuid = fmt::format("uuid: {}", _uuid);
    std::string app_key = fmt::format("appKey: {}", _app_key);
    std::string timestamp = fmt::format("timeMillis: {}", utils::getTimeStamp());
    std::string sig_value = utils::getSignature(_uuid, _app_key, _app_secret, timestamp, _movecard);
    std::string signature = fmt::format("signature: {}", sig_value);
    
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    headers = curl_slist_append(headers, uuid.c_str());
    headers = curl_slist_append(headers, app_key.c_str());
    headers = curl_slist_append(headers, timestamp.c_str());
    headers = curl_slist_append(headers, signature.c_str());

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);

    CURLcode code = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    if (code != CURLE_OK) {
        std::string err_msg = fmt::format("curl_easy_perform() failed: {}", curl_easy_strerror(code));
        fmt::println("error: {}", err_msg);
    }
    
    fmt::println("resp: {}", response);
    
    return response;
}
