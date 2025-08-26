#pragma once
#include <string>

class Option
{
public:
    virtual ~Option() = default;
    const std::string& getConfigKey() const { return mConfigKey; }

protected:
    Option(const std::string& descriptionKey, const std::string& configKey);

private:
    std::string mDescriptionKey;
    std::string mConfigKey;
};