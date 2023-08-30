/**
 * @file dice.h
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Definition of the dice class with its attributes and methods.
 * @version 0.1
 * @date 2023-08-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef DICE_H
#define DICE_H

#include <string>

#define SIDES 6 /**< Numbers of sides. */
#define INITIAL 1 /**< Initial number. */

// Dice class.
class Dice {
public:
   // Contructor dice.
   Dice();
   // Destructor dice.
   ~Dice();

   // Get the random number.
   int getNumber() const;
   // Get the random number symbol.
   std::string getSymbol() const;

   // Roll the dice.
   void roll();
private:
   int sides; /**< Sides of the dice */
   int number; /**< Random number played*/
};

#endif // DICE_H
