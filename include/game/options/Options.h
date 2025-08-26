#pragma once
#include <vector>
#include <memory> // for std::unique_ptr

// --- FORWARD DECLARATIONS ---
// We tell the compiler these classes exist without including their full headers.
class Option;
// --- END FORWARD DECLARATIONS ---

/**
 * @brief The main container for all game options.
 *
 * This class is the C++ representation of the options.txt file.
 * Its constructor (recreated from InitializeGameOptions) is responsible
 * for creating and registering every single option in the game.
 */
class Options
{
public:
    // This is our main analyzed function, InitializeGameOptions
    Options();
    ~Options();

    // In the future, we will add methods to get and set options by name.
    // Option* getOption(const std::string& configKey);

private:
    // A vector of unique_ptrs is the perfect way to store a polymorphic
    // collection of different Option types (IntOption, FloatOption, etc.).
    std::vector<std::unique_ptr<Option>> mOptions;
};