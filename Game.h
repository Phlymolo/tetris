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
    bool gameOver = false;
    int tickRate = 1000; // not const bc we may want to speed/slow the game for difficulty

    // points
    int points = 0;
    int pointsThisTick = 0;
    const int SPAWN_BLOCK_POINTS = 10;
    const int ROW_CLEAR_POINTS = 100;
    const int MULTI_ROW_CLEAR_BONUS = 50;

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
    int run();
    void generateNextBlock();
};

#endif
