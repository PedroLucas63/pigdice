/**
 * @file player.h
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-08-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include "utils.h"

#ifndef PLAYER_H
#define PLAYER_H

// TODO: Comment the code.

#define DEFAULT_NAME "Jack"
#define DEFAULT_SCORE 0
#define DEFAULT_VICTORIES 0
#define DEFAULT_DEFEATS 0
#define DEFAULT_MAXIMUM_SCORE 0

class Player {
public:
    Player();
    Player(std::string name_);
    ~Player();

    std::string getName() const;
    int getScore() const;
    int getVictories() const;
    int getVictories() const;
    int getMaximumScore() const;

    void setName(std::string name_);
    void addScore(int score_);
    void addVictory();
    void addDefeat();
private:
    std::string name;
    int score;
    int victories;
    int defeats;
    int maximum_score;

    void clearScore();
    void checkMaximumScore();
};

#endif // PLAYER_H
