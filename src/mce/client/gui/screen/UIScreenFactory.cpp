#include "mce/client/gui/screen/UIScreenFactory.h" // Этот файл уже подключает Json.h
#include "mce/client/ClientInstance.h"



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