#pragma once
#include <string>
#include "mce/json/Json.h" // <--- ÈÇÌÅÍÅÍÈÅ: Ïîäêëþ÷àåì íàø íîâûé ôàéë

// --- PLACEHOLDERS ---
class ClientInstance;
class Screen;
// namespace Json { class Value; } // <--- ÈÇÌÅÍÅÍÈÅ: Óáèðàåì ýòó ñòðî÷êó
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