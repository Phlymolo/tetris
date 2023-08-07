#include "GameBoard.h"
#include <iostream>

GameBoard::GameBoard()
{
    // Initialize grid to all zeros
    for (int i = 0; i < BoardHeight; ++i)
    {
        for (int j = 0; j < BoardWidth; ++j)
        {
            grid[i][j] = 0;
        }
    }
}

void GameBoard::addBlock(const Block &block)
{
    int posX = block.getPositionX();
    int posY = block.getPositionY();
    const int(*shape)[4] = block.getShape();

    // Add the block's shape to the grid
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (shape[i][j] != 0 && posY + i >= 0)
            {
                grid[posY + i][posX + j] += shape[i][j];
            }
        }
    }
}

void GameBoard::removeBlock(const Block &block)
{
    int posX = block.getPositionX();
    int posY = block.getPositionY();
    const int(*shape)[4] = block.getShape();

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (shape[i][j] != 0 && posY + i >= 0)
            {
                grid[posY + i][posX + j] -= shape[i][j];
            }
        }
    }
}

bool GameBoard::checkCollision(const Block &block)
{
    int posX = block.getPositionX();
    int posY = block.getPositionY();
    const int(*shape)[4] = block.getShape();

    // Check if the block's shape overlaps with anything in the grid
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (shape[i][j] != 0 &&
                (posY + i < 0 || posY + i >= BoardHeight || posX + j < 0 || posX + j >= BoardWidth || grid[posY + i][posX + j] != 0))
            {
                // std::cout << "Collision detected at " << posY + i << ", " << posX + j << std::endl;
                return true;
            }
        }
    }

    // std::cout << "No collision detected" << std::endl;
    return false;
}

void GameBoard::displayBoard() const
{
    std::cout << " - - - - - - - - - -\n"; // top of the board
    for (int i = 0; i < BoardHeight; ++i)
    {
        // Display the row number
        // if (i == 0)
        // {
        //     std::cout << "   ";
        //     for (int j = 0; j < BoardWidth; ++j)
        //     {
        //         std::cout << j;
        //         std::cout << " "; // Extra space after each cell
        //     }
        //     std::cout << '\n';
        // }
        for (int j = 0; j < BoardWidth; ++j)
        {
            if (j == 0)
            {
                // Display the column number
                // std::cout << i;
                // if (i < 10)
                // {
                //     std::cout << " ";
                // }
                std::cout << "|";
            }

            if (grid[i][j] == 0)
            {
                std::cout << ' ';
            }
            else
            {
                std::cout << '#';
            }

            std::cout << " "; // Extra space after each cell

            if (j == BoardWidth - 1)
            {
                std::cout << "|";
            }
        }

        std::cout << '\n';
    }
    std::cout << " - - - - - - - - - -\n"; // bottom of the board
}

int GameBoard::removeFullLines()
{
    int linesCleared = 0;
    for (int y = 0; y < BoardHeight; ++y)
    {
        bool isFull = true;
        for (int x = 0; x < BoardWidth; ++x)
        {
            if (grid[y][x] == 0)
            {
                isFull = false;
                break;
            }
        }

        if (isFull)
        {
            // Shift down all lines above
            for (int aboveY = y - 1; aboveY >= 0; --aboveY)
            {
                for (int x = 0; x < BoardWidth; ++x)
                {
                    grid[aboveY + 1][x] = grid[aboveY][x];
                }
            }

            // Fill the top line with 0's
            for (int x = 0; x < BoardWidth; ++x)
            {
                grid[0][x] = 0;
            }

            // Increment the number of lines cleared
            ++linesCleared;
        }
    }

    return linesCleared;
}
