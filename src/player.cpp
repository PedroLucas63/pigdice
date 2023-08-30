/**
 * @file player.cpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-08-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// TODO: Comment the code.

#include "player.h"

Player::Player() {
    name = DEFAULT_NAME;
    score = DEFAULT_SCORE;
    victories = DEFAULT_VICTORIES;
    defeats = DEFAULT_DEFEATS;
    maximum_score = DEFAULT_MAXIMUM_SCORE;
}

Player::Player(std::string name_) {
    setName(name_);
    score = DEFAULT_SCORE;
    victories = DEFAULT_VICTORIES;
    defeats = DEFAULT_DEFEATS;
    maximum_score = DEFAULT_MAXIMUM_SCORE;
}

Player::~Player() { }

std::string Player::getName() const {
    return name;
}

int Player::getScore() const {
    return score;
}

int Player::getVictories() const {
    return victories;
}

int Player::getVictories() const {
    return defeats;
}

int Player::getMaximumScore() const {
    return maximum_score;
}

void Player::setName(std::string name_) {
    utils::leftTrim(name_);

    if (name_.empty()) {
        name = DEFAULT_NAME;
    } else {
        name = name_;
    }
}

void Player::addScore(int score_) {
    if (score_ < 0) {
        score_ = 0;
    }

    score += score_;
}

void Player::addVictory() {
    ++victories;
    checkMaximumScore();
}

void Player::addDefeat() {
    ++defeats;
    checkMaximumScore();
}

void Player::clearScore() {
    score = DEFAULT_SCORE;
}

void Player::checkMaximumScore() {
    if (score > maximum_score) {
        maximum_score = score;
    }

    clearScore();
}
