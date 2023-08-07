#include "HighScoresManager.h"
#include <fstream>
#include <sstream>
#include <algorithm>

HighScoresManager::HighScoresManager(const std::string &filename)
    : filename(filename)
{
    loadHighScores();
}

bool HighScoresManager::isTop10Score(int score)
{
    if (highScores.size() < 10)
        return true;
    return score > highScores.back().score;
}

void HighScoresManager::addScore(const std::string &initials, int score)
{
    highScores.push_back({initials, score});
    std::sort(highScores.begin(), highScores.end(),
              [](const HighScore &a, const HighScore &b)
              { return a.score > b.score; });
    if (highScores.size() > 10)
        highScores.pop_back();
}

void HighScoresManager::saveHighScores()
{
    std::ofstream file(filename);
    for (const auto &hs : highScores)
    {
        file << hs.initials << "," << hs.score << std::endl;
    }
    file.close();
}

std::vector<std::pair<std::string, int>> HighScoresManager::getHighScores() const
{
    std::vector<std::pair<std::string, int>> highScoresPairs;
    for (const auto &hs : highScores)
    {
        highScoresPairs.push_back({hs.initials, hs.score});
    }

    return highScoresPairs;
}


void HighScoresManager::loadHighScores()
{
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string initials;
        int score;
        std::getline(ss, initials, ',');
        ss >> score;
        highScores.push_back({initials, score});
    }
    file.close();
    std::sort(highScores.begin(), highScores.end(),
              [](const HighScore &a, const HighScore &b)
              { return a.score > b.score; });
}
