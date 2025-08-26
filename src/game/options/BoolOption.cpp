#include "game/options/BoolOption.h"
BoolOption::BoolOption(const std::string& d, const std::string& c, bool def) : Option(d, c), mValue(def), mDefaultValue(def) {}