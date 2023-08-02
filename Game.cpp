#include "Game.h"
#include <iostream>

Game::Game() : currentBlock(nullptr), nextBlock(nullptr)
{
    generateNextBlock();
}

Game::~Game()
{
    delete currentBlock;
    delete nextBlock;
}

void Game::run()
{
    while (true)
    {
        std::cout << "Next tick" << std::endl;

        board.displayBoard();

        if (currentBlock == nullptr)
        {
            std::cout << "Generating new block" << std::endl;
            currentBlock = nextBlock;
            nextBlock = nullptr;
            generateNextBlock();

            // Add the newly created currentBlock to the board
            std::cout << "Adding block to board" << std::endl;
            if (board.checkCollision(*currentBlock))
            {
                std::cerr << "Game Over! A block was generated inside another block!" << std::endl;
                exit(EXIT_FAILURE);
            }
            board.addBlock(*currentBlock);
        }

        // Get input
        std::cout << "Enter a, d, w, or s: (waiting for input)";
        char input;
        std::cin >> input;

        // std::cout << "input: " << input << std::endl;

        // first, remove the block from the board
        board.removeBlock(*currentBlock);
        std::cout << "Removed block from board" << std::endl;
        board.displayBoard();

        switch (input)
        {
        case 'a': // Move left
            currentBlock->moveLeft();
            if (board.checkCollision(*currentBlock))
            {
                // undo the move if there is a collision
                currentBlock->moveRight();
            }
            break;
        case 'd': // Move right
            currentBlock->moveRight();
            if (board.checkCollision(*currentBlock))
            {
                // undo the move if there is a collision
                currentBlock->moveLeft();
            }
            break;
        case 'w': // Rotate
            currentBlock->rotate();
            if (board.checkCollision(*currentBlock))
            {
                // undo the rotation if there is a collision
                for (int i = 0; i < 3; ++i)
                {
                    currentBlock->rotate();
                }
            }
            break;
        case 's': // Move down faster
            currentBlock->moveDown();
            if (board.checkCollision(*currentBlock))
            {
                // undo the move if there is a collision
                currentBlock->moveUp();
            }
            break;
        default:
            break;
        }

        // Move the block down after every tick
        std::cout << "Moving block down, ending positiion" << currentBlock->getPositionX() << ", " << currentBlock->getPositionY() << std::endl;
        currentBlock->moveDown();

        // If there's a collision, move it back up and add it to the board
        if (board.checkCollision(*currentBlock))
        {
            currentBlock->moveUp();
            board.addBlock(*currentBlock);
            delete currentBlock;
            currentBlock = nullptr;
        }
        else{
            //just re-add the block to the board
            board.addBlock(*currentBlock);
        }
        

        // Check for full lines
                
    }
}

void Game::generateNextBlock()
{
    // For now, just generate IBlocks
    nextBlock = new IBlock(BoardWidth / 2 - 2, -1);
}