#pragma once

#include <string>
#include "response.h"

class JLinkClient
{
public:
    JLinkClient(const std::string& uuid, 
                const std::string& app_key, 
                const std::string& app_secret, 
                int movecard);
    
    ~JLinkClient();
    
    std::string request(const std::string& url, const std::string& param);
    
private:
    std::string _uuid;
    std::string _app_key;
    std::string _app_secret;
    int _movecard;
};