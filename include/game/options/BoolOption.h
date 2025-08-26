#pragma once
#include "game/options/Option.h"

class BoolOption : public Option
{
public:
    BoolOption(const std::string& desc, const std::string& config, bool def);
private:
    bool mValue;
    bool mDefaultValue;
};