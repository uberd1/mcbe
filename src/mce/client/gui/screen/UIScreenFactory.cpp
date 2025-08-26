#include "mce/client/gui/screen/UIScreenFactory.h" // Путь к .h файлу изменился
#include "mce/client/ClientInstance.h"

// --- PLACEHOLDERS AND HELPERS ---
namespace Json {
    class Value {
    public:
        Value& operator[](const char* key) { return *this; }
        void operator=(bool value) {}
        void operator=(const std::string& value) {}
    };
}
// --- END PLACEHOLDERS AND HELPERS ---


UIScreenFactory::UIScreenFactory(ClientInstance* client) : mClientInstance(client)
{
}

UIScreenFactory::~UIScreenFactory()
{
}

void UIScreenFactory::prepareScreenDataContext(const std::string& screenName, Screen* screenInstance, Json::Value& dataContext)
{
    SetupUIDisplayConditions(dataContext);
    Json::Value& screenNameField = dataContext["*screen_name*"];
    screenNameField = screenName;
    // screenInstance->applyDataBindings(dataContext);
}

void UIScreenFactory::SetupUIDisplayConditions(Json::Value& dataContext)
{
    ClientInstance* client = GetClientInstance();
    if (!client) return;

    dataContext["$store_disabled"] = false;
    dataContext["$game_pad"] = true;
    dataContext["$mouse"] = false;
    dataContext["$touch"] = false;
    dataContext["$trial"] = false;
    dataContext["$win10_edition"] = true;
    dataContext["$console_edition"] = false;
    dataContext["$pocket_edition"] = false;
    dataContext["$is_holographic"] = false;
    dataContext["$gear_vr"] = false;
    dataContext["$oculus_rift"] = false;
}