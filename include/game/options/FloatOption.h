#pragma once
#include "game/options/Option.h"

class FloatOption : public Option
{
public:
    FloatOption(const std::string& desc, const std::string& config, float def, float min, float max);
private:
    float mValue;
    float mDefaultValue;
    float mMinValue;
    float mMaxValue;
};