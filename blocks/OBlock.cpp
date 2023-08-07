#include "OBlock.h"

OBlock::OBlock(int posX, int posY) : Block(posX, posY)
{
    // initialiize the "shape" which is a 4x4 array of 0s
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j) 
        {
            shape[i][j] = 0;
        }
    }

    // Set the shape of the block using 1s, which in this case (OBlock) is a square of 4 squares
    shape[1][1] = 1;
    shape[1][2] = 1;
    shape[2][1] = 1;
    shape[2][2] = 1;

    // Set the name of the block
    name = "Square/Block/O-Block";        
}


void OBlock::rotate()
{
    // Do nothing
}