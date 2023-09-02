/**
 * @file utils.cpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Implementation of useful functions to the entire project.
 * @version 1.0
 * @date 2023-08-30
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "utils.hpp"

// Utils namespace.
namespace utils {
   // Randomizer a number.
   int rand(int end, int init) {
      std::random_device device;
      std::mt19937 generator(device());

      std::uniform_int_distribution<int> distribution(init, end);

      return distribution(generator);
   }

   // Cut the string to the left.
   void leftTrim(std::string &str, std::string const t) {
      str.erase(0, str.find_first_not_of(t));
   }
} // Namespace utils
