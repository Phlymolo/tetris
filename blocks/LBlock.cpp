#include "LBlock.h"

LBlock::LBlock(int posX, int posY) : Block(posX, posY)
{
    // The initial position of the L block
    shape[1][0] = 1;
    shape[2][0] = 1;
    shape[2][1] = 1;
    shape[2][2] = 1;

    name = "L-Block";
}

void LBlock::rotate()
{
    // Clear the current shape
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            shape[i][j] = 0;
        }
    }

    // Update the rotation state and the shape of the block
    switch (rotationState)
    {
    case 0:
        // Normal L state
        shape[1][0] = 1;
        shape[2][0] = 1;
        shape[3][0] = 1;
        shape[1][1] = 1;
        rotationState = 1;
        break;
    case 1:
        // 90 degrees rotation
        shape[1][0] = 1;
        shape[1][1] = 1;
        shape[1][2] = 1;
        shape[2][2] = 1;
        rotationState = 2;
        break;
    case 2:
        // 180 degrees rotation
        shape[3][0] = 1;
        shape[1][1] = 1;
        shape[2][1] = 1;
        shape[3][1] = 1;
        rotationState = 3;
        break;
    case 3:
        // 270 degrees rotation
        shape[1][0] = 1;
        shape[2][0] = 1;
        shape[2][1] = 1;
        shape[2][2] = 1;
        rotationState = 0;
        break;
    }
}
