/**
 * @file player.cpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Implementation of the players class with its attributes and methods.
 * @version 0.1
 * @date 2023-08-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "player.h"

/**
 * @brief Construct a new Player object with the specified name.
 * 
 * @param name_ Player name.
 */
Player::Player(std::string name_) {
    setName(name_);
    score = DEFAULT_SCORE;
    victories = DEFAULT_VICTORIES;
    defeats = DEFAULT_DEFEATS;
    high_score = DEFAULT_HIGH_SCORE;
}

/**
 * @brief Destroy the Player object.
 * 
 */
Player::~Player() { }

/**
 * @brief Get player name.
 * 
 * @return The name.
 */
std::string Player::getName() const {
    return name;
}

/**
 * @brief Get player score.
 * 
 * @return The score. 
 */
int Player::getScore() const {
    return score;
}

/**
 * @brief Get number of wins from the player.
 * 
 * @return Number of victories.
 */
int Player::getVictories() const {
    return victories;
}

/**
 * @brief Get the player's number of defeats
 * 
 * @return Number of defeats.
 */
int Player::getDefeats() const {
    return defeats;
}

/**
 * @brief Get the player's high score.
 * 
 * @return The high score.
 */
int Player::getHighScore() const {
    return high_score;
}

/**
 * @brief Set the player name.
 * 
 * @param name_ Name to set.
 */
void Player::setName(std::string name_) {
    utils::leftTrim(name_);

    if (name_.empty()) {
        name = DEFAULT_NAME;
    } else {
        name = name_;
    }
}

/**
 * @brief Add score to total.
 * 
 * @param score_ Additional score.
 */
void Player::addScore(int score_) {
    score = score_ < MINIMUM_SCORE ? MINIMUM_SCORE : score_;
}

/**
 * @brief Add new victory.
 * 
 */
void Player::addVictory() {
    ++victories;
    checkHighScore();
}

/**
 * @brief Add new defeat.
 * 
 */
void Player::addDefeat() {
    ++defeats;
    checkHighScore();
}

/**
 * @brief Clear score.
 * 
 */
void Player::clearScore() {
    score = DEFAULT_SCORE;
}

/**
 * @brief Checks if the game's score was the player's highest score.
 * 
 */
void Player::checkHighScore() {
    if (score > high_score) {
        high_score = score;
    }

    clearScore();
}
