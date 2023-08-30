/**
 * @file dice.cpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-08-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// TODO: Comment the code.

#include "dice.h"
#include "utils.h"

Dice::Dice() { 
   sides = DEFAULT_SIDES;
   roll();
}

Dice::~Dice() { }

void Dice::roll() {
   number = utils::rand(sides, INITIAL);
}

int Dice::getNumber() const {
   return number;
}

char Dice::getSymbol() const {
   char dice;

   switch (number) {
   case 1:
      dice = '⚀';
      break;
   case 2:
      dice = '⚁';
      break;
   case 3:
      dice = '⚂';
      break;
   case 4:
      dice = '⚃';
      break;
   case 5:
      dice = '⚄';
      break;
   default:
      dice = '⚅';
      break;
   }

   return dice;
}