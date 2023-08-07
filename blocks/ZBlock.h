#ifndef ZBLOCK_H
#define ZBLOCK_H

#include "Block.h"

class ZBlock : public Block
{
private:
    int rotationState = 0;

public:
    ZBlock(int posX, int posY);

    // Override the rotate method
    void rotate() override;
};

#endif