/*!
 * Main program, which should contain the main game loop.
 *
 * \author
 * \date
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <memory>
#include <iterator>

#include "pigdice_common.h"
#include "player.h"

// === Auxiliary functions to help user input

/// Trim off white spaces from left part of a string.
inline std::string& ltrim(std::string& s, const char* t = " \t\n\r\f\v")
{
    s.erase(0, s.find_first_not_of(t));
    return s;
}

// === Regular methods of the Player class.


