#include "Block.h"
#include <string>


Block::Block(int posX, int posY) : positionX(posX), positionY(posY)
{
    // Initialize shape array to all zeros
    resetShape();
}

void Block::resetShape()
{
    // Initialize shape array to all zeros
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            shape[i][j] = 0;
        }
    }
}

int Block::getPositionX() const
{
    return positionX;
}

int Block::getPositionY() const
{
    return positionY;
}

const int (*Block::getShape() const)[4]
{
    return shape;
}

void Block::moveLeft()
{
    --positionX;
}

void Block::moveRight()
{
    ++positionX;
}

void Block::moveDown()
{
    ++positionY;
}

void Block::moveUp()
{
    --positionY;
}

const std::string& Block::getName() const 
{
    return name;
}


