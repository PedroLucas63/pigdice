/**
 * @file ai_player.cpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Implements machine decision-making functions.
 * @version 1.0
 * @date 2023-08-30
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "ai_player.h"

// Decides whether the player should play
bool decideRoll(Player const &player, Player const &adversary) {
   int difference { adversary.getScore() - player.getScore() };
   /* The number 8 is defined by the algorithm presented in the reference */
   int max_value { DEFAULT_SCORE_FETCHED + difference / 8 };
   int total_score { player.getScore() + player.getTurnScore() };
   int missing_score { WINNERS_SCORE - player.getScore() };

   bool roll { false };

   if (total_score >= WINNERS_SCORE) {
      roll = false;
   } else if (adversary.getScore() >= EXTREME_DANGER_ZONE) {
      roll = true;
   } else if (player.getTurnScore() < max_value) {
      roll = true;
   } else if (adversary.getScore() >= DANGER_ZONE) {
      /*
       * The following logic, with the whole number divided by 3/5, considers
       * avoiding very long moves even if the opponent is in the danger zone.
       * Example: The opponent has 71 points and the machine only 45. It
       * wouldn't be wise for the machine to try to win 55 points in a single
       * move, but it should take a chance and try to get at least 3/5 of that
       * value to try to win on the next move if the opponent doesn't.
       */
      roll = (missing_score * 3) / 5 > player.getTurnScore() ? true : false;
   }

   return roll;
}
