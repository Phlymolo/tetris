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
            // std::cout << "Key pressed: " << ch << std::endl;
            switch (ch)
            {
            case 'a': // Move left
                currentBlock->moveLeft();
                if (board.checkCollision(*currentBlock))
                {
                    // std::cout << "collision" << std::endl;

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
            case 'q': // Quit
                // std::cout << "Quitting..." << std::endl;
                // exit(EXIT_SUCCESS);
                gameOver = true;
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
    pointsThisTick = 0;

    // If there's no "current" block
    // 1. Check for full lines
    // 2. Create a new current block from the next block
    // 3. Check for collision with the new block. If there is one, then game over
    // 4. Reset the "next" block
    if (currentBlock == nullptr)
    {
        std::cout << "No current block" << std::endl;
        // Check for full lines
        int linesCleared = board.removeFullLines();
        pointsThisTick += linesCleared * ROW_CLEAR_POINTS + (linesCleared > 1 ? MULTI_ROW_CLEAR_BONUS : 0);

        // Spawn a new block by setting currentBlock to nextBlock
        currentBlock = nextBlock;
        nextBlock = nullptr;
        generateNextBlock();
        if (board.checkCollision(*currentBlock))
        {
            gameOver = true;
            return;
        }

        // Reset the "next" block
        // nextBlock = nullptr;
        // generateNextBlock();

        board.addBlock(*currentBlock);
        pointsThisTick += SPAWN_BLOCK_POINTS;
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

    // Update points
    // std::cout << "Points this tick: " << pointsThisTick << std::endl;
    points += pointsThisTick;
    // std::cout << "Total points: " << points << std::endl;
}

void Game::render()
{
    board.setPointsThisTick(pointsThisTick);
    board.setPoints(points);
    board.setNextBlock(nextBlock);
    board.displayBoard();
}

int Game::run()
{
    auto nextTickTime = std::chrono::steady_clock::now();
    while (gameOver == false)
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
        }

        // Sleep so we don't max out the CPU
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    return points;
}

void Game::generateNextBlock()
{
    // For now, just generate IBlocks
    nextBlock = new IBlock(BoardWidth / 2 - 2, -1);
}