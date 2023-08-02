#include "IBlock.h"

IBlock::IBlock(int posX, int posY) : Block(posX, posY)
{    
    // initialiize the "shape" which is a 4x4 array of 0s
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            shape[i][j] = 0;
        }
    }

    // Set the shape of the block using 1s, which in this case (IBLock) is a straight line of 4 squares
    for (int j = 0; j < 4; ++j)
    {
        shape[1][j] = 1;
    }
}

void IBlock::rotate()
{
    int tempShape[4][4];

    // Create a temp array to hold the rotated shape
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            tempShape[j][i] = shape[i][j];
        }
    }

    // Rotate the shape by swapping rows with columns
    for (int i = 0, k = 3; i < 2; ++i, --k)
    {
        for (int j = 0; j < 4; ++j)
        {
            int temp = tempShape[i][j];
            tempShape[i][j] = tempShape[k][j];
            tempShape[k][j] = temp;
        }
    }

    // Copy the rotated shape back to the shape array
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            shape[i][j] = tempShape[i][j];
        }
    }
}