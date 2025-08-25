#include <iostream>

#include "mce/platform/DeviceInfo.h"
#include "mce/client/gui/screen/SettingsScreen.h"
#include "mce/common/sound/SoundManager.h"
#include "mce/render/GraphicsDevice.h"

struct GraphicsInfo;
GraphicsInfo* GetGlobalGraphicsInfo();

int main()
{
    std::cout << "--- Testing DeviceInfo ---" << std::endl;
    DeviceInfo myDevice;
    std::cout << "Device ID: " << myDevice.deviceId << std::endl;

    std::cout << "\n--- Testing SettingsScreen ---" << std::endl;
    SettingsScreen mySettingsScreen;
    std::cout << "SettingsScreen object created successfully!" << std::endl;

    std::cout << "\n--- Testing SoundManager ---" << std::endl;
    SoundManager soundManager;
    std::cout << "Dispatching sound event 'ui.button.press'..." << std::endl;
    soundManager.playSoundEvent("ui.button.press", false, false, 1.0f, 1.0f);
    std::cout << "Sound event dispatched successfully!" << std::endl;

    std::cout << "\n--- Testing GraphicsDevice ---" << std::endl;

    GraphicsInfo* graphicsInfo = GetGlobalGraphicsInfo();
    std::cout << "Successfully got GraphicsInfo object." << std::endl;

    GraphicsDevice graphicsDevice;
    bool success = graphicsDevice.Initialize(graphicsInfo);

    if (success) {
        std::cout << "GraphicsDevice initialized successf