#ifndef TBLOCK_H
#define TBLOCK_H

#include "Block.h"

class TBlock : public Block
{
private:
    int rotationState = 0; // keep track of the rotation state to more easily rotate the block
public:
    TBlock(int posX, int posY);

    // Override the rotate method
    void rotate() override;
};

#endif