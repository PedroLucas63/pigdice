/**
 * @file player.cpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Implementation of the players class with its attributes and methods.
 * @version 1.0
 * @date 2023-08-30
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "player.hpp"

// Constructor with name
Player::Player(std::string name_) {
   setName(name_);
   turn_score = DEFAULT_SCORE;
   score = DEFAULT_SCORE;
}

// Destructor
Player::~Player() { }

// Get player name
std::string Player::getName() const {
   return name;
}

// Get player turn score
int Player::getTurnScore() const {
   return turn_score;
}

// Get player score
int Player::getScore() const {
   return score;
}

// Get game logs
std::vector<utils::RoundLog> const *Player::getLogs() const {
   return &logs;
}

// Set player name
void Player::setName(std::string name_) {
   utils::leftTrim(name_);

   if (name_.empty()) {
      name = DEFAULT_NAME;
   } else {
      name = name_;
   }
}

// Add turn score
void Player::addTurnScore(int turn_score_) {
   turn_score += turn_score_ > MINIMUM_SCORE ? turn_score_ : MINIMUM_SCORE;
}

// Clear turn score
void Player::clearTurnScore() {
   turn_score = DEFAULT_SCORE;
}

// Add score
void Player::addScore() {
   score += turn_score;
}

// Add log
void Player::addLog(utils::RoundLog log_) {
   logs.push_back(log_);
}
