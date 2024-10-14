#pragma once

#include <string>

namespace utils {

std::string getTimeStamp();

std::string getSignature(const std::string& uuid, 
                         const std::string& app_key, 
                         const std::string& app_secret, 
                         const std::string& timestamp,
                         int movecard);

}