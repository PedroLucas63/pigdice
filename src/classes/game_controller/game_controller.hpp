/**
 * @file game_controller.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Definition of the game manager class with its attributes and methods.
 * @version 1.0
 * @date 2023-08-30
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef PIGDICE_GAME_HPP_
#define PIGDICE_GAME_HPP_

#include "dice.hpp"
#include "player.hpp"
#include "utils.hpp"
using utils::HUMAN;
using utils::MACHINE;
#include <iomanip>
#include <iostream>
using std::cout;

#define WINNERS_SCORE 100    /**< Score to win */
#define NUMBERS_OF_PLAYERS 2 /**< Number of players */
#define COLUMN_SIZE 11       /**< Table column size */
#define PIG_DICE 1           /**< Pig number on the dice */
#define KEY_ROLL "r"         /**< Roll key */
#define KEY_HOLD "h"         /**< Hold key */
#define KEY_QUIT "q"         /**< Quit key */
#define KEY_CONFIRM "y"      /**< Confirm key */

/**
 * @brief Definition of player class
 *
 */
class GameController {
   /* Definition of enumerations */
   /**
    * @brief Game state enumeration
    *
    */
   enum GameState {
      STARTING,
      WELCOME,
      PLAYING,
      ROLLING,
      HOLDING,
      UPDATING_SCORE,
      WINNER,
      QUITTING,
      ENDING,
   };

   /**
    * @brief Player actions enumeration
    *
    */
   enum Action {
      ROLL,
      HOLD,
      QUIT,
      END,
      NONE,
   };

   /* Definition of attributes */
   Dice dice;                          /**< Dice */
   Player players[NUMBERS_OF_PLAYERS]; /**< Players */
   Player *current_player;             /**< Pointer to current player */
   Player *winner;                     /**< Pointer to winner */
   utils::RoundLog round_log;          /**< Round log */
   GameState state;                    /**< Game state */
   Action action;                      /**< Player action */

   /* Definition of private methods */
   /**
    * @brief Prompts pressing enter
    *
    */
   void pressEnter();

   /**
    * @brief Manages who performs the move and saves the data
    *
    */
   void getPlay();

   /**
    * @brief Receives action from human player
    *
    */
   void getHumanAction();

   /**
    * @brief Get the action from the machine
    *
    */
   void getMachineAction();

   /**
    * @brief Receive quitting confirmation
    *
    */
   void confirmQuiting();

   /**
    * @brief Check what the player's action is and change the game state
    *
    */
   void performAction();

   /**
    * @brief Rolls the dice and manages state and records
    *
    */
   void rollingDice();

   /**
    * @brief Hold score, save records and update state
    *
    */
   void holdingScore();

   /**
    * @brief Clear round log
    *
    */
   void clearRoundLog();

   /**
    * @brief Check if there was a win in the round
    *
    */
   void checkWinner();

   /**
    * @brief Change current player
    *
    */
   void switchPlayer();

   /**
    * @brief Checks if the game has ended
    *
    */
   void verifyEnding();

   /**
    * @brief Displays the main menu
    *
    */
   void showMenu() const;

   /**
    * @brief Displays input commands
    *
    */
   void showCommands() const;

   /**
    * @brief Displays the total score for the turn
    *
    */
   void showTurnTotal() const;

   /**
    * @brief Displays the total score of players
    *
    */
   void showScores() const;

   /**
    * @brief Displays the quitting confirmation question
    *
    */
   void showQuitting() const;

   /**
    * @brief Displays the winner of the game
    *
    */
   void showWinner() const;

   /**
    * @brief Displays the play logs of the two players
    *
    */
   void showLogs() const;

   /**
    * @brief Displays the shutdown message
    *
    */
   void showEnding() const;

 public:
   /**
    * @brief Construct a new game controller object
    *
    */
   GameController();

   /**
    * @brief Destroy the Game Controller object
    *
    */
   ~GameController();

   /**
    * @brief Initialize the GameController with the player's name
    *
    * @param player_name Player's name
    */
   void initialize(std::string player_name);

   /**
    * @brief Returns if the game is over
    *
    * @return Game shutdown status
    */
   bool gameOver() const;

   /**
    * @brief Manages data entry, based on state
    *
    */
   void processEvents();

   /**
    * @brief Updates game state based on input and previous state
    *
    */
   void update();

   /**
    * @brief Render UI, based on state
    *
    */
   void render() const;
};

#endif // PIGDICE_GAME_HPP_