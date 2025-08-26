#pragma once
#include "game/options/Option.h"
#include <string>

class StringOption : public Option
{
public:
    StringOption(const std::string& desc, const std::string& config, const std::string& def);
private:
    std::string mValue;
    std::string mDefaultValue;
};