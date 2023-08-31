/**
 * @file ai_player.h
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Defines the machine's decision-making functions.
 * @version 0.1
 * @date 2023-08-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "player.h"

#ifndef AI_PLAYER_H
#define AI_PLAYER_H

#define DANGER_ZONE 71 /**< Danger zone */
#define EXTREME_DANGER_ZONE 88 /**< Extreme danger zone */
#define DEFAULT_SCORE_FETCHED 21 /**< Standard score fetched */

// Decides whether the player should play
bool decideRoll(Player* player, Player* adversary);

#endif // AI_PLAYER_H
