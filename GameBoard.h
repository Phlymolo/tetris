#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include "Block.h"

const int BoardWidth = 10;
const int BoardHeight = 20;

class GameBoard
{
private:
    int grid[BoardHeight][BoardWidth];
    int points = 0;
    int pointsThisTick = 0;
    Block *nextBlock;


public:
    GameBoard();

    void addBlock(const Block &block);
    void removeBlock(const Block &block);
    bool checkCollision(const Block &block);    
    void displayBoard() const;
    int removeFullLines();
    void setPoints(int points){
        this->points = points;
    }
    void setPointsThisTick(int pointsThisTick){
        this->pointsThisTick = pointsThisTick;
    }
    void setNextBlock(Block *nextBlock){
        this->nextBlock = nextBlock;
    }
};

#endif
