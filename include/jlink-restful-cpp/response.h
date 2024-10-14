#pragma once

#include <string>
#include "json/json.hpp"

template <typename T>
class Response
{
public:
    int code;
    std::string msg;
    T data;
};

namespace nlohmann
{
template <typename T>
struct adl_serializer<Response<T>>
{
    static void from_json(const json& j, Response<T>& out)
    {
        out.code = j.value("code", 404);
        if (j.contains("msg")) {
            out.msg = j.value("msg", "Not Found");
        } else if (j.contains("error_msg")) {
            out.msg = j.value("error_msg", "Not Found");
        } else {
            out.msg = "Not Found";
        }

        out.data = j;
    }
};
} // namespace nlohmann

#include "response/null_response.h"
#include "response/device_list_response.h"