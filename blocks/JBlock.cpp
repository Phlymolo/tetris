#include "JBlock.h"

JBlock::JBlock(int posX, int posY) : Block(posX, posY)
{
    // The initial position of the L block
    shape[1][0] = 1;
    shape[2][0] = 1;
    shape[2][1] = 1;
    shape[2][2] = 1;

    name = "J-Block";
}

void JBlock::rotate()
{
    // Clear the current shape
   resetShape();

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
