/**
 * @file dice.cpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Implementation of dice class methods.
 * @version 0.1
 * @date 2023-08-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "dice.h"
#include "utils.h"

/**
 * @brief Construct a new Dice object.
 * 
 */
Dice::Dice() { 
   sides = SIDES;
   roll();
}

/**
 * @brief Destroy the Dice object.
 * 
 */
Dice::~Dice() { }

/**
 * @brief Roll the dice.
 * 
 */
void Dice::roll() {
   number = utils::rand(sides, INITIAL);
}

/**
 * @brief Get the random number.
 * 
 * @return The number. 
 */
int Dice::getNumber() const {
   return number;
}

/**
 * @brief Get the data symbol from the generated random number.
 * 
 * @return The symbol.
 */
std::string Dice::getSymbol() const {
   std::string dice;

   switch (number) {
   case 1:
      dice = "⚀";
      break;
   case 2:
      dice = "⚁";
      break;
   case 3:
      dice = "⚂";
      break;
   case 4:
      dice = "⚃";
      break;
   case 5:
      dice = "⚄";
      break;
   default:
      dice = "⚅";
      break;
   }

   return dice;
}
