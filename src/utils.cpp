/**
 * @file utils.cpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Implementation of useful functions to the entire project.
 * @version 0.1
 * @date 2023-08-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "utils.h" // rand, leftTrim

namespace utils {
   /**
    * @brief Randomizes a number with marsenne twitter in the range.
    * 
    * @note The interval is [init, end].
    * 
    * @param end Last number (included)
    * @param init First number (included)
    * @return A randomizer number.
    */
   int rand(int end, int init = 0) {
      std::random_device device;
      std::mt19937 generator(device());

      std::uniform_int_distribution<int> distribution(init, end);

      return distribution(generator);
   }

   /**
    * @brief Trim left elements that match one of the target elements.
    * 
    * @param str String to cut.
    * @param t Target to search.
    */
   void leftTrim(std::string& str, std::string const t = " \t\n\r\f\v") {
      str.erase(0, str.find_first_not_of(t));
   }
}