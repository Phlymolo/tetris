#ifndef JBLOCK_H
#define JBLOCK_H

#include "Block.h"

class JBlock : public Block
{
private:
    int rotationState = 0; //keep track of the rotation state to more easily rotate the block

public:
    JBlock(int posX, int posY);

    // Override the rotate method
    void rotate() override;
};

#endif