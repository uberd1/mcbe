#pragma once
#include <string>

// --- PLACEHOLDERS ---
class ClientInstance;
class Screen;
namespace Json { class Value; }
// --- END PLACEHOLDERS ---

class UIScreenFactory
{
public:
    UIScreenFactory(ClientInstance* client);
    ~UIScreenFactory();

    void prepareScreenDataContext(const std::string& screenName, Screen* screenInstance, Json::Value& dataContext);

private:
    void SetupUIDisplayConditions(Json::Value& dataContext);

    ClientInstance* mClientInstance;
};