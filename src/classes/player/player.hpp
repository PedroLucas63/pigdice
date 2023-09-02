/**
 * @file player.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Definition of the player class with its attributes and methods.
 * @version 1.0
 * @date 2023-08-30
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "utils.hpp"
#include <vector>

#define DEFAULT_NAME "Ned"          /**< Default name for the player */
#define DEFAULT_MACHINE_NAME "Ilyn" /**< Default name for the machine */
#define DEFAULT_SCORE 0             /**< Default score for the player */
#define DEFAULT_ROUND 0             /**< Default score round for the player */
#define MINIMUM_SCORE 0             /**< Minimum score in round */

/**
 * @brief Definition of player class
 *
 */
class Player {
   /* Definition of attributes */
   std::string name;                  /**< Player name */
   int turn_score;                    /**< Player turn score */
   int score;                         /**< Player score */
   std::vector<utils::RoundLog> logs; /**< Game logs */
 public:
   /**
    * @brief Construct a new Player object with the specified name
    *
    * @param name_ Player name
    */
   Player(std::string name_ = DEFAULT_NAME);

   /**
    * @brief Destroy the Player object
    *
    */
   ~Player();

   /**
    * @brief Get player name
    *
    * @return The name
    */
   std::string getName() const;

   /**
    * @brief Get player turn score
    *
    * @return The turn score
    */
   int getTurnScore() const;

   /**
    * @brief Get player score
    *
    * @return The score
    */
   int getScore() const;

   /**
    * @brief Get game logs
    *
    * @return The logs
    */
   std::vector<utils::RoundLog> const *getLogs() const;

   /**
    * @brief Set the player name
    *
    * @param name_ Name to set
    */
   void setName(std::string name_);

   /**
    * @brief Add score to turn
    *
    * @param turn_score_ Additional turn score
    */
   void addTurnScore(int turn_score_);

   /**
    * @brief Clear turn score
    *
    */
   void clearTurnScore();

   /**
    * @brief Add score to total
    *
    * @param score_ Additional score
    */
   void addScore();

   /**
    * @brief Adds a new log to the vector
    *
    * @param log_ Log to add
    */
   void addLog(utils::RoundLog log_);
};

#endif // PLAYER_HPP_
