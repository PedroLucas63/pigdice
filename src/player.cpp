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
Player::Player(std::string name_, PlayerType type_) {
    setName(name_);
    type = type_;
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
 * @brief Get player type.
 * 
 * @return The type. 
 */
PlayerType Player::getType() const {
    return type;
}

/**
 * @brief Get player turn score.
 * 
 * @return The turn score. 
 */
int Player::getTurnScore() const {
    return turn_score;
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
 * @brief Add score to turn.
 * 
 * @param turn_score_ Additional turn score.
 */
void Player::addTurnScore(int turn_score_) {
    turn_score += turn_score_ > MINIMUM_SCORE ? turn_score_ : MINIMUM_SCORE;
}

/**
 * @brief Add score to total.
 * 
 * @param score_ Additional score.
 */
void Player::addScore() {
    score += turn_score;
    clearTurnScore();
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
 * @brief Clear turn score.
 * 
 */
void Player::clearTurnScore() {
    turn_score = DEFAULT_SCORE;
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

    clearTurnScore();
    clearScore();
}
