/**
 * @file ai_player.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Defines the machine's decision-making functions.
 * @version 1.0
 * @date 2023-08-30
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef AI_PLAYER_HPP_
#define AI_PLAYER_HPP_

#include "game_controller.hpp"
#include "player.hpp"

#define DANGER_ZONE 71           /**< Danger zone */
#define EXTREME_DANGER_ZONE 88   /**< Extreme danger zone */
#define DEFAULT_SCORE_FETCHED 21 /**< Standard score fetched */

/**
 * @brief Decides whether the player rolls the dice again
 *
 * @note 'End race or keep pace'. If either player has a score of 71 or higher,
 * roll to win. Otherwise, hold on 21 plus the difference between scores
 * divided by 8. This has a 0.9% disadvantage against optimal play.
 * [Look here.](https://en.wikipedia.org/wiki/Pig_(dice_game))
 *
 * @param player Player to decide
 * @param players All players in the game
 * @param number_of_player Number of players
 * @return Whether to roll the dice or not
 */
bool decideRoll(Player const *player, Player *const players,
   size_t number_of_players);

/**
 * @brief Filters the current player from other opponents
 *
 * @param player Player to decide
 * @param players All players in the game
 * @param number_of_player Number of players
 * @param adversaries List of other opponents to be selected
 */
void getAdversaries(Player const *player, Player *const players,
   size_t number_of_players, Player *adversaries);

#endif // AI_PLAYER_HPP_
