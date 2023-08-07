#ifndef OBLOCK_H
#define OBLOCK_H

#include "Block.h"

class OBlock : public Block
{
public:
    OBlock(int posX, int posY);

    // Override the rotate method
    void rotate() override;
};

#endif