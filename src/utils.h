/**
 * @file utils.h
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Definition of useful functions to the entire project.
 * @version 0.1
 * @date 2023-08-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef UTILS_H
#define UTILS_H

#include <random> //  random_device, mt19937, uniform_int_distribution

// Utils namespace.
namespace utils {
   // Randomizer a number.
   int rand(int end, int init = 0);

   // Cut the string to the left.
   void leftTrim(std::string& str, std::string const t = " \t\n\r\f\v");
}

#endif // UTILS_H
