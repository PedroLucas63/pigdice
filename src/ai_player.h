/**
 * @file ai_player.h
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Defines the machine's decision-making functions.
 * @version 1.0
 * @date 2023-08-30
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef AI_PLAYER_H
#define AI_PLAYER_H

#include "player.h"
#include "pigdice_game.h"

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
 * @param adversary Opposing player
 * @return Whether to roll the dice or not
 */
bool decideRoll(Player const &player, Player const &adversary);

#endif // AI_PLAYER_H
