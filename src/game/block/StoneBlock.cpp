#include "game/block/StoneBlock.h"

/**
 * @brief Constructor for the StoneBlock class.
 *
 * @param name The unique string identifier for the block ("stone").
 * @param id The numeric ID for the block (1).
 */
StoneBlock::StoneBlock(const std::string& name, int id)
// This is the most important part: the member initializer list.
// The ": Block(name, id)" part calls the constructor of the parent Block class
// and passes the name and id up to it.
    : Block(name, id)
{
    // Inside the constructor's body, we set the unique properties for Stone.
    // These are the values we saw being set in MinecraftBlocks_Init.

    setHardness(1.5f);
    setExplosionResistance(10.0f);
    setMaterial(2); // In the original code, this was a direct memory write.
}