#ifndef HIGHSCOREMANAGER_H
#define HIGHSCOREMANAGER_H

#include <string>
#include <vector>

class HighScoresManager
{
public:
    HighScoresManager(const std::string &filename);
    bool isTop10Score(int score);
    void addScore(const std::string &initials, int score);
    void saveHighScores();
    std::vector<std::pair<std::string, int>> getHighScores() const;

private:
    struct HighScore
    {
        std::string initials;
        int score;
    };

    void loadHighScores();

    std::vector<HighScore> highScores;
    std::string filename;
};

#endif