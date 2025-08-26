#include <iostream>

// ���������� "�������" ���� ����� �������
#include "game/block/StoneBlock.h"
#include "mce/client/ClientInstance.h"
#include "mce/client/gui/screen/SettingsScreen.h"
#include "mce/client/gui/screen/UIScreenFactory.h"
#include "mce/common/sound/SoundManager.h"
#include "mce/core/TelemetryManager.h"
#include "mce/platform/DeviceInfo.h"
#include "mce/render/GraphicsDevice.h"
#include "mce/render/ShaderManager.h"
#include "mce/json/Json.h"

// --- �������� / ���������� ---
// ��� ���������� �����, ����� main.cpp ���� � ����� � ��������,
// ���������� ������� ��������� � ������ .cpp ������.
struct GraphicsInfo;
GraphicsInfo* GetGlobalGraphicsInfo();
namespace Json { class Value; } // �������� ��� JSON-�������
// --- ����� �������� ---


int main()
{
    std::cout << "--- Project mcbe ---" << std::endl;
    std::cout << "Testing all created class skeletons...\n" << std::endl;

    // ������� ���������� ���� ����� ������� �� �������

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

    // ClientInstance - ��� ��������, �� �� ������� ��� ��������, � �������� ����� ������
    ClientInstance* ci = GetClientInstance();
    std::cout << "-> GetClientInstance() called." << std::endl;

    TelemetryManager telemetryManager;
    std::cout << "-> TelemetryManager created." << std::endl;

    UIScreenFactory uiFactory(ci);
    std::cout << "-> UIScreenFactory created." << std::endl;


    std::cout << "\n--- Running initializers for testing ---" << std::endl;

    // �������� �������� ������, ����� ���������, ��� ��� ����������
    GraphicsInfo* graphicsInfo = GetGlobalGraphicsInfo();
    graphicsDevice.Initialize(graphicsInfo);
    std::cout << "-> GraphicsDevice::Initialize() called." << std::endl;

    Json::Value testContext;
    uiFactory.prepareScreenDataContext("start_screen", nullptr, testContext);
    std::cout << "-> UIScreenFactory::prepareScreenDataContext() called." << std::endl;

    telemetryManager.SendHardwareInfoEvent();
    std::cout << "-> TelemetryManager::SendHardwareInfoEvent() called." << std::endl;


    std::cout << "\nSuccess! All classes are included and compiling. Press Enter to exit." << std::endl;
    std::cin.get();

    return 0;
}