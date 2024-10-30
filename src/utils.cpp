#include <chrono>
#include "fmt/core.h"
#include "openssl/md5.h"
#include "openssl/evp.h"
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

std::string getSignature(const DeveloperInfo& develop_info,
                         const std::string& timestamp)
{
    std::string data_0 = fmt::format("{}{}{}{}", develop_info.uuid, develop_info.app_key, develop_info.app_secret, timestamp);
    std::string data_1 = data_0;
    size_t len = data_1.length();
    for (int i = 0; i < len; i++) {
        char tmp = (i % develop_info.movecard) > (len - i) % develop_info.movecard ? data_1[i] : data_1[len - (i + 1)];
        data_1[i] = data_1[len - (i + 1)];
        data_1[len - (i + 1)] = tmp;
    }

    size_t len_0 = data_0.length();
    std::string data_2(len_0 * 2, '\0');

    for (int i = 0; i < len_0; i++) {
        data_2[i] = data_0[i];
        data_2[len_0 * 2 - 1 - i] = data_1[i];
    }

    unsigned char hash_value[16] = {};
    MD5((unsigned char*)data_2.c_str(), len_0 * 2, hash_value);

    std::string hex;
    for (int i = 0; i < 16; i++) {
        hex.append(fmt::format("{:02x}", hash_value[i]));
    }

    return hex;
}

std::string AESEncode(const std::string& in, const DeveloperInfo& developer_info, const std::string& timestamp)
{
    std::string out;
    std::string key = timestamp.substr(timestamp.length() / 2);
    key += developer_info.app_secret;
    key = key.substr(0, 16);
    
    // key = "5234675401002cbf";
    
    unsigned char* p_key = (unsigned char*)key.c_str();
    unsigned char* p_in = (unsigned char*)in.c_str();
    unsigned char p_out[1024] = {};
    int out_len = 1024;
    
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit(ctx, EVP_aes_128_ecb(), p_key, nullptr);
    EVP_CIPHER_CTX_set_padding(ctx, EVP_PADDING_PKCS7);
    EVP_EncryptUpdate(ctx, p_out, &out_len, p_in, (int)in.length());
    out.append((char*)p_out, out_len);
    EVP_EncryptFinal(ctx, p_out, &out_len);
    out.append((char*)p_out, out_len);
    EVP_CIPHER_CTX_free(ctx);

    std::string hex;
    for (int i = 0; i < out.length(); i++) {
        hex.append(fmt::format("{:02x}", out[i]));
    }

    std::transform(hex.begin(), hex.end(), hex.begin(), [](unsigned char c) { return std::toupper(c); });
    return hex;
}

} // namespace utils
