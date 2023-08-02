#ifndef GAME_H
#define GAME_H

#include "GameBoard.h"
#include "IBlock.h"

class Game
{
private:
    GameBoard board;
    Block *currentBlock;
    Block *nextBlock;

public:
    Game();
    ~Game();
    void run();
    void generateNextBlock();
};

#endif
