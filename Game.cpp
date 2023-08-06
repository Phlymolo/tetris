#include "Game.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>

Game::Game() : currentBlock(nullptr), nextBlock(nullptr)
{
    generateNextBlock();
}

Game::~Game()
{
    delete currentBlock;
    delete nextBlock;
}

void Game::handleInput()
{
    auto startTime = std::chrono::steady_clock::now();
    auto waitTime = std::chrono::milliseconds(50); // Wait for 50 ms

    if (currentBlock == nullptr)
    {
        // then leave the function
        return;
    }

    // we need to remove the blcok from the board before we check for collisions
    board.removeBlock(*currentBlock);

    while (std::chrono::steady_clock::now() - startTime < waitTime)
    {
        if (_kbhit())
        {
            char ch = _getch();
            std::cout << "Key pressed: " << ch << std::endl;
            switch (ch)
            {
            case 'a': // Move left
                currentBlock->moveLeft();
                std::cout << "move left" << std::endl;
                if (board.checkCollision(*currentBlock))
                {
                    std::cout << "collision" << std::endl;

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
            case '1': // Quit
                std::cout << "Quitting..." << std::endl;
                exit(EXIT_SUCCESS);
                break;
            default:
                break;
            }
            break;
            // continue; // keep registering input until waitTime is up
        }

        // Sleep for a brief period to avoid busy-waiting
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }

    // re-add the block to the board
    board.addBlock(*currentBlock);
}

void Game::tick()
{
    // std::cout << "Next tick" << std::endl;

    if (currentBlock == nullptr)
    {
        // Check for full lines
        int linesCleard = board.removeFullLines();
        points += linesCleard * linesCleard * 100;

        currentBlock = nextBlock;
        nextBlock = nullptr;
        generateNextBlock();
        if (board.checkCollision(*currentBlock))
        {
            std::cerr << "Game Over! A block was generated inside another block!" << std::endl;
            exit(EXIT_FAILURE);
        }

        board.addBlock(*currentBlock);
    }

    // first, remove the block from the board
    board.removeBlock(*currentBlock);

    // Move the block down after every tick
    currentBlock->moveDown();

    // If there's a collision, move it back up and add it to the board
    if (board.checkCollision(*currentBlock))
    {
        currentBlock->moveUp();
        board.addBlock(*currentBlock);
        delete currentBlock;
        currentBlock = nullptr;
    }
    else
    {
        // just re-add the block to the board
        board.addBlock(*currentBlock);
    }
}

void Game::render()
{
    board.displayBoard();
}

void Game::run()
{
    int tickRate = 500;
    auto nextTickTime = std::chrono::steady_clock::now();

    while (true)
    {
        // Process any user input
        handleInput();

        // Update game state
        if (std::chrono::steady_clock::now() >= nextTickTime)
        {
            tick();
            nextTickTime += std::chrono::milliseconds(tickRate); // Schedule next tick

            // Render the game
            render();
            displayPoints();
        }

        // // Render the game
        // render();

        // Sleep to avoid using 100% CPU
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void Game::generateNextBlock()
{
    // For now, just generate IBlocks
    nextBlock = new IBlock(BoardWidth / 2 - 2, -1);
}