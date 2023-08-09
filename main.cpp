#include "Game.h"
#include "HighScoresManager.h"
#include <iostream>
#include <limits>

// prototypes
int getMenuChoice();
int getValidatedIntegerInput(int min, int max);
int playGame();
void viewHighScores(std::vector<std::pair<std::string, int>> highScores);

// main
int main()
{
    std::cout << "Welcome to Tetris!" << std::endl;

    // create a HighScoresManager object and pass it the filename of the high scores file
    HighScoresManager highScoresManager("highscores.txt");

    // seed the random number generator (used for block generation)
    srand(time(NULL));

    // init variables used in the menu
    int score = 0;
    int choice = 0;
    
    // main menu loop
    while (choice != 3)
    {
        choice = getMenuChoice();
        switch (choice)
        {
        case 1:
            score = playGame();
            if (highScoresManager.isTop10Score(score))
            {
                std::string initials;
                std::cout << "Congratulations! Your score made it to the top 10." << std::endl;
                std::cout << "Would you like to add your score to the high scores list? (y/n): ";
                char addScore = 'n';
                std::cin >> addScore;
                if (addScore != 'y' && addScore != 'Y')
                {
                    break;
                }
                std::cout << "Enter your initials: ";
                std::cin.width(4);
                std::cin >> initials;
                highScoresManager.addScore(initials, score);
                highScoresManager.saveHighScores();

                // display the high scores
                viewHighScores(highScoresManager.getHighScores());
            }
            break;
        case 2:
            viewHighScores(highScoresManager.getHighScores());
            break;

        default:
            break;
        }
    }

    std::cout << "Thanks for playing!" << std::endl;

    return 0;
}

int getMenuChoice()
{
    int choice = 0;
    std::cout << std::endl << "Main menu" << std::endl;
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

void viewHighScores(std::vector<std::pair<std::string, int>> highScores)
{
    std::cout << std::endl << "High Scores" << std::endl;
    std::cout << "-----------" << std::endl;
    for (const auto &hs : highScores)
    {
        std::cout << hs.first << " " << hs.second << std::endl;
    }
}
