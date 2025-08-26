#pragma once
#include "game/options/Option.h"

class IntOption : public Option
{
public:
    IntOption(const std::string& desc, const std::string& config, int def, int min, int max);
private:
    int mValue;
    int mDefaultValue;
    int mMinValue;
    int mMaxValue;
};