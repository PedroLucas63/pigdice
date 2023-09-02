/**
 * @file common.h
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Definition of enumerations and common structures in the project.
 * @version 1.0
 * @date 2023-09-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef COMMON_H
#define COMMON_H

/**
* @brief Player type.
* 
*/
enum PlayerType {
   HUMAN,
   MACHINE,
};

/**
 * @brief Round log struct.
 * 
 */
struct RoundLog {
   int score { 0 };
   int turns { 0 };
};

#endif // COMMON_H
