#pragma once
#include <string>

// --- PLACEHOLDERS ---
// ¬ будущем здесь будут другие типы, например, Material.
// --- END PLACEHOLDERS ---

/**
 * @brief The base class for all blocks in the game.
 *
 * Recreated based on the analysis of MinecraftBlocks_Init.
 * It defines the common properties and behaviors that all blocks share.
 */
class Block
{
public:
    // This is the constructor we see being called, e.g., sub_71012DD110("stone", &id)
    Block(const std::string& name, int id);
    virtual ~Block(); // Destructors for base classes should always be virtual

    // --- Chainable Setters ---
    // These are the methods like setHardness, setExplosionResistance, etc.
    // They return 'Block*' to allow chaining: stone->setHardness(1.5f)->setExplosionResistance(10.0f);

    virtual Block* setHardness(float hardness);
    virtual Block* setExplosionResistance(float resistance);
    virtual Block* setMaterial(int materialId); // PLACEHOLDER for Material class
    // ... many more methods will be added here as we find them ...

private:
    // --- Member Variables (Fields) ---
    // These store the properties for each block instance.

    std::string mName;                // e.g., "stone"
    int mId;                          // e.g., 1
    float mHardness;                  // e.g., 1.5f
    float mExplosionResistance;       // e.g., 10.0f
    int mMaterialId;                  // e.g., 2 (for "stone" material)
};