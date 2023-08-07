#include "OBlock.h"

OBlock::OBlock(int posX, int posY) : Block(posX, posY)
{
    shape[1][1] = 1;
    shape[1][2] = 1;
    shape[2][1] = 1;
    shape[2][2] = 1;

    name = "O-Block";
}

void OBlock::rotate()
{
    // Do nothing
}