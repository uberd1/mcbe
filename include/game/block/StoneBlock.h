#pragma once
#include "game/block/Block.h" // Подключаем "чертеж" нашего родительского класса

/**
 * @brief Represents the Stone block in the game.
 *
 * This is one of the first concrete block classes we are recreating.
 * It inherits all the properties and methods from the base Block class.
 */
class StoneBlock : public Block
{
public:
    // The constructor for StoneBlock.
    // It simply calls the constructor of its parent class, Block.
    StoneBlock(const std::string& name, int id);
};