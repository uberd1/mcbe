#include <iostream>

#include "mce/platform/DeviceInfo.h"
#include "mce/client/gui/screen/SettingsScreen.h"
#include "mce/common/sound/SoundManager.h"
#include "mce/render/GraphicsDevice.h"
#include "mce/render/ShaderManager.h"
#include "game/block/Block.h"
#include "game/block/StoneBlock.h"
#include "mce/client/ClientInstance.h"
#include "mce/core/TelemetryManager.h"

struct GraphicsInfo;
GraphicsInfo* GetGlobalGraphicsInfo();

int main()
{
    std::cout << "--- Project mcbe ---" << std::endl;
    std::cout << "Testing class skeletons...\n" << std::endl;

    DeviceInfo myDevice;
    std::cout << "-> DeviceInfo created." << std::endl;

    SettingsScreen mySettingsScreen;
    std::cout << "-> SettingsScreen created." << std::endl;

    SoundManager soundManager;
    std::cout << "-> SoundManager created." << std::endl;

    GraphicsDevice graphicsDevice;
    std::cout << "-> GraphicsDevice created." << std::endl;

    ShaderManager shaderManager;
    std::cout << "-> ShaderManager created." << std::endl;

    StoneBlock myStone("stone", 1);
    std::cout << "-> StoneBlock created." << std::endl;

    ClientInstance* ci = GetClientInstance();
    std::cout << "-> GetClientInstance() called." << std::endl;

    TelemetryManager telemetryManager;
    telemetryManager.SendHardwareInfoEvent();
    std::cout << "-> TelemetryManager methods called." << std::endl;

    std::cout << "\n--- Running Initializers ---" << std::endl;
    GraphicsInfo* graphicsInfo = GetGlobalGraphicsInfo();
    std::cout << "-> Successfully got GraphicsInfo object." << std::endl;
    bool success = graphicsDevice.Initialize(graphicsInfo);
    if (success) {
        std::cout << "-> GraphicsDevice initialized successfully!" << std::endl;
    }
    else {
        std::cout << "-> GraphicsDevice failed to initialize." << std::endl;
    }

    std::cout << "\nSuccess! All classes are included and compiling. Press Enter to exit." << std::endl;
    std::cin.get();

    return 0;
}