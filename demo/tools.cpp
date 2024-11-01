#include <chrono>
#include <fstream>
#include <thread>
#include "fmt/core.h"
#include "openssl/md5.h"
#include "tools.h"

// 获取参数
void getParams(Params& params)
{
    std::ifstream file("./config.ini");
    if (!file) {
        std::cerr << "文件打开失败" << std::endl;
    }

    try {
        std::string line;
        while (std::getline(file, line)) {
            size_t pos = line.find('=');
            if (pos == std::string::npos)
                continue; // 跳过没有等号的行

            // 提取键和值
            std::string key = line.substr(0, pos);
            std::string value = line.substr(pos + 1);

            if (key == "uuid") {
                params._uuid = value;
            } else if (key == "app_key")
                params._app_key = value;
            else if (key == "app_secret")
                params._app_secret = value;
            else if (key == "movecard")
                params._movecard = std::stoi(value); // string转int
            else if (key == "dev_sn")
                params._dev_sn = value;
            else if (key == "dev_user_name")
                params._dev_user_name = value;
            else if (key == "dev_password")
                params._dev_password = value;
        }
    } catch (...) {
        std::cerr << "参数获取失败，请检查参数" << std::endl;
    }
    file.close();
}