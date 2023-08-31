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
#include "pigdice_game.h"

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
   /* The number 8 is defined by the algorithm presented in the reference. */
   int max_value { DEFAULT_SCORE_FETCHED + difference / 8 };
   int total_score { player.getScore() + player.getTurnScore() };
   int missing_score { WINNERS_SCORE - player.getScore() };

   bool roll { false };
   
   if (total_score >= WINNERS_SCORE) {
      roll = false;
   } else if (adversary.getScore() >= EXTREME_DANGER_ZONE) {
      roll = true;
   } else if (player.getTurnScore() < difference) {
      roll = true;
   } else if (adversary.getScore() >= DANGER_ZONE) {
      /*
       * The following logic, with the whole number divided by 2/3, considers
       * avoiding very long moves even if the opponent is in the danger zone.
       * Example: The opponent has 71 points and the machine only 45. It
       * wouldn't be wise for the machine to try to win 55 points in a single
       * move, but it should take a chance and try to get at least 2/3 of that
       * value to try to win on the next move if the opponent doesn't.
       */
      roll = (missing_score * 2) / 3 > adversary.getTurnScore() ? true : false;
   }

   return roll;
}
