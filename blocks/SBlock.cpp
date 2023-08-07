#include "SBlock.h"

SBlock::SBlock(int posX, int posY) : Block(posX, posY)
{
    shape[1][1] = 1;
    shape[1][2] = 1;
    shape[2][0] = 1;
    shape[2][1] = 1;

    name = "S-Block";
}

void SBlock::rotate()
{
    resetShape();

    switch (rotationState)
    {
    case 0:
        shape[1][1] = 1;
        shape[1][2] = 1;
        shape[0][1] = 1;
        shape[2][2] = 1;
        rotationState = 1;
        break;
    case 1:
        shape[2][1] = 1;
        shape[2][2] = 1;
        shape[1][2] = 1;
        shape[1][3] = 1;
        rotationState = 2;
        break;
    case 2:
        shape[1][1] = 1;
        shape[2][1] = 1;
        shape[2][2] = 1;
        shape[3][2] = 1;
        rotationState = 3;
        break;
    case 3:
        shape[1][1] = 1;
        shape[1][2] = 1;
        shape[2][0] = 1;
        shape[2][1] = 1;
        rotationState = 0;
        break;
    }
}