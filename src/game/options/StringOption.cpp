#include "game/options/StringOption.h"
StringOption::StringOption(const std::string& d, const std::string& c, const std::string& def) : Option(d, c), mValue(def), mDefaultValue(def) {}