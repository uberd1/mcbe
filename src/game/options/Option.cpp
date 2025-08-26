#include "game/options/Option.h"

Option::Option(const std::string& descriptionKey, const std::string& configKey)
    : mDescriptionKey(descriptionKey),
    mConfigKey(configKey)
{
}