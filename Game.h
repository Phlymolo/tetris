#ifndef GAME_H
#define GAME_H

#include "GameBoard.h"
#include "IBlock.h"
#include <iostream>

class Game
{
private:
    GameBoard board;
    Block *currentBlock;
    Block *nextBlock;
    int points = 0;

    void displayPoints() const
    {
        std::cout << "Points: " << points << std::endl;
    }

public:
    Game();
    ~Game();
    void handleInput();
    void tick();
    void render();
    void run();
    void generateNextBlock();
};

#endif
