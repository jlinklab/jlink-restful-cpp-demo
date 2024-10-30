#pragma once
#include <string>
#include "jlink_client.h"
#include "jlink_device.h"
#include "jlink_developer.h"
#include "fmt/core.h"

namespace utils
{

std::string getTimeStamp();

std::string getSignature(const DeveloperInfo& developer_info, const std::string& timestamp);

std::string AESEncode(const std::string& ori_data, const DeveloperInfo& developer_info, const std::string& timestamp);

} // namespace utils