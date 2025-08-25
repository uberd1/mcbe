#pragma once
#include <string>
#include <vector>

// --- PLACEHOLDERS ---

class RenderGlobals;
class JsonValue;
// --- END PLACEHOLDERS ---


class ShaderManager
{
public:

    ShaderManager();


    ~ShaderManager();

    void initializeFromJson(RenderGlobals* globals, const std::string& uniformsJson);

private:

    std::vector<void*> mUniformDefinitions; // PLACEHOLDER

    char unknown_data[24]; // PLACEHOLDER for unanalyzed fields
};