#include <chrono>
#include "fmt/core.h"
#include "openssl/md5.h"
#include "utils.h"

namespace utils
{

std::string getTimeStamp()
{
    static int i = 0;
    if (++i >= 1000000) {
        i = 1;
    }

    std::string prefix = fmt::format("{:07}", i);
    auto t = std::chrono::system_clock::now().time_since_epoch();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(t).count();

    return fmt::format("{}{}", prefix, ms);
}

std::string getSignature(const std::string& uuid,
                         const std::string& app_key,
                         const std::string& app_secret,
                         const std::string& timestamp,
                         int movecard)
{
    std::string data_0 = fmt::format("{}{}{}{}", uuid, app_key, app_secret, timestamp);
    std::string data_1 = data_0;
    size_t len = data_1.length();
    for(int i = 0; i < len; i++) {
        char tmp = (i % movecard) > (len - i) % movecard ? data_1[i] : data_1[len - (i + 1)];
        data_1[i] = data_1[len - (i + 1)];
        data_1[len - (i + 1)] = tmp;
    }
    
    size_t len_0 = data_0.length();
    std::string data_2(len_0 * 2, '\0');
    
    for(int i = 0; i < len_0; i++) {
        data_2[i] = data_0[i];
        data_2[len_0 * 2 - 1 - i] = data_1[i];
    }

    unsigned char hash_value[16] = {};
    MD5((unsigned char*)data_2.c_str(), len_0 * 2, hash_value);

    std::string hex;
    for(int i = 0; i < 16; i++) {
        hex.append(fmt::format("{:02x}", hash_value[i]));
    }

    return hex;
}

} // namespace utils