#include "Game.h"
#include <iostream>
#include <limits>

// prototypes
int getMenuChoice();
int getValidatedIntegerInput(int min, int max);
int playGame();
void viewHighScores();

// main
int main()
{
    int choice = getMenuChoice();
    switch (choice)
    {
    case 1:
        playGame();
        break;
    case 2:
        viewHighScores();
        break;

    case 3:
        std::cout << "Thanks for playing!" << std::endl;
        break;

    default:
        break;
    }

    return 0;
}

int getMenuChoice()
{
    int choice = 0;
    std::cout << "Welcome to Tetris!" << std::endl;
    std::cout << "1. Play!" << std::endl;
    std::cout << "2. View High Scores" << std::endl;
    std::cout << "3. Quit" << std::endl;
    std::cout << "Enter your choice: ";

    choice = getValidatedIntegerInput(1, 3);
    return choice;
}

int getValidatedIntegerInput(int min, int max)
{
    int choice;

    while (!(std::cin >> choice) || choice < min || choice > max)
    {
        std::cout << "Invalid selection. Please enter a number " << min << " - " << max << ": ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return choice;
}

int playGame()
{
    Game game;
    int score = game.run();
    std::cout << "Your score was: " << score << std::endl;

    return score;
}

void viewHighScores()
{
    std::cout << "High Scores" << std::endl;
}
