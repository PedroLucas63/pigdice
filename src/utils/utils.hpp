/**
 * @file utils.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Definition of useful functions to the entire project.
 * @version 1.0
 * @date 2023-08-30
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <random> //  random_device, mt19937, uniform_int_distribution

/**
 * @brief Definition of useful items for the entire system.
 *
 */
namespace utils {
   /**
    * @brief Player type.
    *
    */
   enum PlayerType {
      HUMAN,
      MACHINE,
   };

   /**
    * @brief Player position.
    * 
    */
   enum PlayerPosition {
      PLAYER1,
      PLAYER2,
   };

   /**
    * @brief Round log struct.
    *
    */
   struct RoundLog {
      int score { 0 };
      int turns { 0 };
   };

   /**
    * @brief Randomizes a number with mersenne twister in the range.
    *
    * @note The interval is [init, init + numbers).
    *
    * @param numbers Amount of numbers (not included)
    * @param init First number (included)
    * @return A randomized number.
    */
   int rand(int numbers, int init = 0);

   /**
    * @brief Trim left elements that match one of the target elements.
    *
    * @param str String to cut.
    * @param t Target to search.
    */
   void leftTrim(std::string &str, std::string const t = " \t\n\r\f\v");
} // Namespace utils

#endif // UTILS_HPP_
