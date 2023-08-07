#ifndef IBLOCK_H
#define IBLOCK_H

#include "Block.h"

class IBlock : public Block
{
public:
    IBlock(int posX, int posY);

    // Override the rotate method
    void rotate() override;
};

#endif
