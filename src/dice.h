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

#ifndef DICE_H
#define DICE_H

// TODO: Comment the code.

#define DEFAULT_SIDES 6
#define INITIAL 1

class Dice {
public:
   Dice();
   ~Dice();

   int getNumber() const;
   char getSymbol() const;

   void roll();
private:
   int sides;
   int number;
};

#endif // DICE_H