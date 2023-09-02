/**
 * @file main.cpp
 *
 * @description
 * This program implements an interactive Pig Dicegame.
 *
 * ===========================================================================
 * @license
 *
 * This file is part of PIG DICE GAME project.
 *
 * PIG DICE GAME is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PIG DICE GAME is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with SUDOKU GAME.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright (C) 2014-2022 Selan R. dos Santos, http://www.dimap.ufrn.br/~selan
 * ===========================================================================
 *
 * @author	Selan R dos Santos, <selan.santos@ufrn.br>
 * @date	2022
 *
 * @remark On 2022-03-22 refactoring to proper game-loop architecture
 */

#include "game_controller.hpp"
#include <string>

#define ARGUMENTS_WITH_NAME 2 /**< Number of arguments if past name */
#define NAME_INDEX 1          /**< Name position index */

/**
 * @brief Returns the name if it exists
 *
 * @param argc Arguments count
 * @param argv Arguments values
 * @return Name
 */
std::string processName(int argc, char *argv[]);

int main(int argc, char *argv[]) {
   GameController game;

   game.initialize(processName(argc, argv));

   while (!game.gameOver()) {
      game.processEvents();
      game.update();
      game.render();
   }

   return EXIT_SUCCESS;
}

// Process name
std::string processName(int argc, char *argv[]) {
   std::string name;

   if (argc == ARGUMENTS_WITH_NAME) {
      name = argv[NAME_INDEX];
   }

   return name;
}
