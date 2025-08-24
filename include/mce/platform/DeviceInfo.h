#pragma once
#include <string>

class DeviceInfo
{
public:
    DeviceInfo();
    ~DeviceInfo();

    std::string platformName;
    std::string deviceId;
    std::string ipAddress;
};