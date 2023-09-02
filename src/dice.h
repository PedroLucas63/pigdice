/**
 * @file dice.h
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Definition of the dice class with its attributes and methods.
 * @version 1.0
 * @date 2023-08-30
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DICE_H
#define DICE_H

#include "utils.h"
#include <string>

#define SIDES 6   /**< Numbers of sides */
#define INITIAL 1 /**< Initial number */

/**
 * @brief Definition of dice class
 *
 */
class Dice {
   /* Definition of attributes */
   int sides;  /**< Sides of the dice */
   int number; /**< Random number played */
 public:
   /**
    * @brief Construct a new Dice object
    *
    */
   Dice();

   /**
    * @brief Destroy the Dice object
    *
    */
   ~Dice();

   /**
    * @brief Roll the dice
    *
    */
   void roll();

   /**
    * @brief Get the random number
    *
    * @return The number.
    */
   int getNumber() const;

   /**
    * @brief Get the data symbol from the generated random number
    *
    * @return The symbol.
    */
   std::string getSymbol() const;
};

#endif // DICE_H
