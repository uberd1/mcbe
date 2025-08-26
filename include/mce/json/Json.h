#pragma once

// This is a placeholder for a real JSON library.
// It allows our code to compile while we focus on the game's architecture.
namespace Json {
    class Value {
    public:
        Value& operator[](const char* key) { return *this; }
        void operator=(bool value) {}
        void operator=(const std::string& value) {}
    };
}