/**
 * @file dice.cpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Implementation of dice class methods.
 * @version 1.0
 * @date 2023-08-30
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "dice.hpp"

// Contructor dice
Dice::Dice() {
   sides = SIDES;
   roll();
}

// Destructor dice
Dice::~Dice() { }

// Roll the dice
void Dice::roll() {
   number = utils::rand(sides, INITIAL);
}

// Get the random number
int Dice::getNumber() const {
   return number;
}

// Get the random number symbol
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
