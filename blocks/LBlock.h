#ifndef LBLOCK_H
#define LBLOCK_H

#include "Block.h"

class LBlock : public Block
{
private:
    int rotationState = 0; //keep track of the rotation state to more easily rotate the block

public:
    LBlock(int posX, int posY);

    // Override the rotate method
    void rotate() override;
};

#endif