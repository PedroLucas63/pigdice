/**
 * @file player.h
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Definition of the player class with its attributes and methods.
 * @version 0.1
 * @date 2023-08-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "utils.h"

#define DEFAULT_NAME "Jack" /**< Default name for the player. */
#define DEFAULT_SCORE 0 /**< Default score for the player. */
#define DEFAULT_VICTORIES 0 // Default victories for the player. */
#define DEFAULT_DEFEATS 0 /**< Default defeats for the player. */
#define DEFAULT_HIGH_SCORE 0 // Player default high score. */
#define MINIMUM_SCORE 0 /**< Minimum score in play. */

// Player class.
class Player {
public:
    // Constructor with name.
    Player(std::string name_ = DEFAULT_NAME);
    // Destructor.
    ~Player();

    // Get player name.
    std::string getName() const;
    // Get player turn score.
    int getTurnScore() const;
    // Get player score.
    int getScore() const;
    // Get number of wins from the player.
    int getVictories() const;
    // Get the player's number of defeats
    int getDefeats() const;
    // Get the player's high score.
    int getHighScore() const;

    // Set player name.
    void setName(std::string name_);
    // Add turn score.
    void addTurnScore(int turn_score_);
    // Add score.
    void addScore();
    // Add victory.
    void addVictory();
    ///Add defeat.
    void addDefeat();
private:
    std::string name; /**< Player name */
    int turn_score; /**< Player turn score */
    int score; /**< Player score */
    int victories; /**< Number of wins */
    int defeats; /**< Number of defeats */
    int high_score; /**< Player high score */

    // Clear turn score.
    void clearTurnScore();
    // Clear score.
    void clearScore();
    // Check high score.
    void checkHighScore();
};

#endif // PLAYER_H
