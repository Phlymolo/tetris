#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "Block.h"

const int BoardWidth = 10;
const int BoardHeight = 20;

class GameBoard
{
private:
    int grid[BoardHeight][BoardWidth];

public:
    GameBoard();

    void addBlock(const Block &block);
    void removeBlock(const Block &block);
    bool checkCollision(const Block &block);
    void clearLine(int line);
    void displayBoard() const;
    int removeFullLines();
};

#endif
