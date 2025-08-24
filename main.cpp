#include <iostream>

#include "mce/platform/DeviceInfo.h"
#include "mce/client/gui/screen/SettingsScreen.h"

int main()
{
    std::cout << "--- Testing DeviceInfo ---" << std::endl;

    DeviceInfo myDevice;

    std::cout << "Platform: " << myDevice.platformName << std::endl;
    std::cout << "Device ID: " << myDevice.deviceId << std::endl;
    std::cout << "IP Address: " << myDevice.ipAddress << std::endl;

    std::cout << "\n--- Testing SettingsScreen ---" << std::endl;

    SettingsScreen mySettingsScreen;

    std::cout << "SettingsScreen object created successfully!" << std::endl;

    std::cout << "\nSuccess! Press Enter to exit." << std::endl;

    std::cin.get();

    return 0;
}