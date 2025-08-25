#include "game/block/Block.h"

/**
 * @brief Constructor for the Block class.
 *
 * @param name The unique string identifier for the block (e.g., "stone").
 * @param id The numeric ID for the block.
 */
Block::Block(const std::string& name, int id)
// This is a member initializer list. It's the standard C++ way
// to initialize fields in a constructor.
    : mName(name),
    mId(id),
    mHardness(0.0f),
    mExplosionResistance(0.0f),
    mMaterialId(0)
{
    // The constructor body is empty because all initialization
    // is done in the initializer list above.
}

/**
 * @brief Destructor for the Block class.
 */
Block::~Block()
{
    // This is empty because our class doesn't manage any raw memory
    // that needs to be manually freed. The std::string members
    // clean up after themselves automatically.
}

/**
 * @brief Sets the hardness (how long it takes to mine) for the block.
 * @return Returns 'this' to allow for chainable calls.
 */
Block* Block::setHardness(float hardness)
{
    this->mHardness = hardness;
    return this;
}

/**
 * @brief Sets the explosion resistance for the block.
 * @return Returns 'this' to allow for chainable calls.
 */
Block* Block::setExplosionResistance(float resistance)
{
    this->mExplosionResistance = resistance;
    return this;
}

/**
 * @brief Sets the material type for the block.
 * @return Returns 'this' to allow for chainable calls.
 */
Block* Block::setMaterial(int materialId)
{
    this->mMaterialId = materialId;
    return this;
}