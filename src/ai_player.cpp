/**
 * @file ai_player.cpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Implements machine decision-making functions.
 * @version 0.1
 * @date 2023-08-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "ai_player.h"

/**
 * @brief Decides whether the player rolls the dice again.
 *
 * @note 'End race or keep pace'. If either player has a score of 71 or higher,
 * roll to win. Otherwise, hold on 21 plus the difference between scores
 * divided by 8. This has a 0.9% disadvantage against optimal play.
 * [Look here.](https://en.wikipedia.org/wiki/Pig_(dice_game))
 * 
 * @param player Player to decide.
 * @param adversary Opposing player.
 * @return Whether to roll the dice or not.
 */
bool decideRoll(Player const& player, Player const& adversary) {
   int difference { adversary.getScore() - player.getScore() };
   int max_value { DEFAULT_SCORE_FETCHED + difference / 8 };

   if (adversary.getScore() >= DANGER_ZONE) {
      return true;
   } else if (player.getTurnScore() < max_value) {
      return true;
   }

   return false;
}
