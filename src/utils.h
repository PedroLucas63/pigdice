/**
 * @file utils.h
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Definition of useful functions to the entire project.
 * @version 1.0
 * @date 2023-08-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef UTILS_H
#define UTILS_H

#include <random> //  random_device, mt19937, uniform_int_distribution

/**
 * @brief Definition of useful functions for the entire system.
 * 
 */
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
   int rand(int end, int init = 0);

   /**
    * @brief Trim left elements that match one of the target elements.
    * 
    * @param str String to cut.
    * @param t Target to search.
    */
   void leftTrim(std::string& str, std::string const t = " \t\n\r\f\v");
}

#endif // UTILS_H
