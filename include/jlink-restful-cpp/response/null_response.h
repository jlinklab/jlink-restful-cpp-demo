﻿#pragma once

#include "response.h"
#include "json/json.hpp"

class Null
{
};

namespace nlohmann
{
template <>
struct adl_serializer<Null>
{
    static void from_json(const json& j, Null& info) { }
};
} // namespace nlohmann


using DeviceBindResponse = Response<Null>;
using DeviceUnBindResponse = Response<Null>;