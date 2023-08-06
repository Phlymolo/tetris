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
    // std::cout << "Adding block to board" << std::endl;
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
    // std::cout << "Checking collision" << std::endl;
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

void GameBoard::clearLine(int line)
{
    std::cout << "Clearing line" << std::endl;
    // Remove the line from the grid and shift everything above it down
    for (int i = line; i > 0; --i)
    {
        for (int j = 0; j < BoardWidth; ++j)
        {
            grid[i][j] = grid[i - 1][j];
        }
    }
    // Clear the top row
    for (int j = 0; j < BoardWidth; ++j)
    {
        grid[0][j] = 0;
    }
}

void GameBoard::displayBoard() const
{
    system("cls");
    std::cout << "----------------------\n"; // top of the board
    for (int i = 0; i < BoardHeight; ++i)
    {
        if (i == 0)
        {
            std::cout << "   ";
            for (int j = 0; j < BoardWidth; ++j)
            {
                std::cout << j;
                std::cout << " "; // Extra space after each cell
            }
            std::cout << '\n';
        }
        for (int j = 0; j < BoardWidth; ++j)
        {
            if (j == 0)
            {
                std::cout << i;
                if (i < 10)
                {
                    std::cout << " ";
                }
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
    std::cout << "----------------------\n"; // bottom of the board
}
