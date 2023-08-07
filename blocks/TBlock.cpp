#include "TBlock.h"

TBlock::TBlock(int posX, int posY) : Block(posX, posY)
{
    shape[1][0] = 1;
    shape[1][1] = 1;
    shape[1][2] = 1;
    shape[2][1] = 1;

    name = "T-Block";
}

void TBlock::rotate()
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
    // Normal T state 
    case 0:
        //rotate clockwise 90 degrees to state 1
        shape[0][1] = 1;
        shape[1][1] = 1;
        shape[2][1] = 1;
        shape[1][0] = 1;
        rotationState = 1;
        break;
    case 1:
        //rotate clockwise 90 degrees to state 2
        shape[1][0] = 1;
        shape[1][1] = 1;
        shape[1][2] = 1;
        shape[0][1] = 1;
       
        rotationState = 2;
        break;
    case 2:
        //rotate clockwise 90 degrees to state 3
        shape[0][1] = 1;
        shape[1][1] = 1;
        shape[2][1] = 1;
        shape[1][2] = 1;
       
        rotationState = 3;
        break;
    case 3:
        // 270 degrees rotation
        shape[1][0] = 1;
        shape[1][1] = 1;
        shape[1][2] = 1;
        shape[2][1] = 1;
        rotationState = 0;
        break;
    }
}