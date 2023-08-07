#ifndef SBLOCK_H
#define SBLOCK_H

#include "Block.h"

class SBlock : public Block
{
private:
    int rotationState = 0;

public:
    SBlock(int posX, int posY);

    // Override the rotate method
    void rotate() override;
};

#endif