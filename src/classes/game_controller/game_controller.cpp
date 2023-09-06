/**
 * @file game_controller.cpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Implementation of the methods of the game manager class.
 * @version 1.0
 * @date 2023-08-30
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "game_controller.hpp"
#include "ai_player.hpp"

/**
 * @brief Actions in string format
 *
 */
std::string const str_actions[] {
   "Select",
   "Information",
   "Create",
   "Play",
   "Roll",
   "Hold",
   "Quit",
   "End",
   "None",
};

std::string const default_names[] {
   "Daenerys",
   "Jon Snow",
   "Cersei",
   "Robb Stark",
   "Arya Stark",
};

// Constructor
GameController::GameController() { }
// Destructor
GameController::~GameController() { }

// Initialize game controller information
void GameController::initialize() {
   number_of_players = 0;
   current_player = nullptr;
   adversary_player = nullptr;
   winner = nullptr;
   state = STARTING;
   action = NONE;
}

// End of game
bool GameController::gameOver() const {
   return state == ENDING;
}

// Process the events
void GameController::processEvents() {
   switch (state) {
   case MENU:
      getMenuAction();
      break;
   case CREATE_PLAYERS:
      getPlayer();
      break;
   case ABOUT:
      pressEnter();
      break;
   case PLAYING:
      getPlay();
      break;
   case UPDATING_SCORE:
      pressEnter();
      break;
   case QUITTING:
      confirmQuitting();
      break;
   default:
      break;
   }
}

// Update the states
void GameController::update() {
   switch (state) {
   case STARTING:
      sortPlayer();
      break;
   case MENU:
      performMenuAction();
      break;
   case CREATE_PLAYERS:
      createPlayer();
      break;
   case ABOUT:
      state = MENU;
      break;
   case PLAYING:
      performPlayerAction();
      break;
   case ROLLING:
      state = PLAYING;
      break;
   case HOLDING:
      state = UPDATING_SCORE;
      break;
   case UPDATING_SCORE:
      checkWinner();
      break;
   case QUITTING:
      verifyEnding();
      break;
   case WINNER:
      state = ENDING;
      break;
   default:
      break;
   }
}

// Render the UI
void GameController::render() const {
   switch (state) {
   case MENU:
      showMenu();
      break;
   case CREATE_PLAYERS:
      showCreatePlayer();
      break;
   case ABOUT:
      showAbout();
      break;
   case PLAYING:
      showCommands();
      break;
   case ROLLING:
      showTurnTotal();
      break;
   case HOLDING:
      showTurnTotal();
      break;
   case UPDATING_SCORE:
      showScores();
      break;
   case QUITTING:
      showQuitting();
      break;
   case WINNER:
      showWinner();
      showLogs();
      break;
   case ENDING:
      showEnding();
      break;
   default:
      break;
   }
}

// Enter to continue
void GameController::pressEnter() {
   std::string buffer;
   std::getline(std::cin, buffer);
}

// Get the menu action
void GameController::getMenuAction() {
   std::string action_;

   std::getline(std::cin, action_);

   action_ = std::tolower(*action_.begin());

   if (action_ == KEY_ABOUT) {
      action = INFORMATION;
   } else if (action_ == KEY_QUIT) {
      action = QUIT;
   } else {
      action = SELECT;
   }
}

void GameController::getPlayer() {
   std::string player_name;

   std::getline(std::cin, player_name);

   if (player_name == KEY_ENTER) {
      action = PLAY;
   } else {
      buffer_name = player_name;
      action = CREATE;
   }
}

// Defines the player and move
void GameController::getPlay() {
   if (current_player->getType() == HUMAN) {
      getHumanAction();
   } else {
      getMachineAction();
   }
}

// Receives input from the human
void GameController::getHumanAction() {
   std::string action_;

   std::getline(std::cin, action_);

   action_ = std::tolower(*action_.begin());

   if (action_ == KEY_HOLD) {
      action = HOLD;
   } else if (action_ == KEY_QUIT) {
      action = QUIT;
   } else {
      action = ROLL;
   }
}

// Receives input from the machine
void GameController::getMachineAction() {
   bool roll { decideRoll(current_player, adversary_player) };

   if (roll) {
      action = ROLL;
   } else {
      action = HOLD;
   }
}

// Receive confirmation of departure
void GameController::confirmQuitting() {
   std::string confirm;

   std::getline(std::cin, confirm);

   confirm = std::tolower(*confirm.begin());

   if (confirm == KEY_CONFIRM) {
      action = END;
   }
}

// Sort first player
void GameController::sortPlayer() {
   int sorted_player { utils::rand(2) };

   if (sorted_player == PLAYER1) {
      current_player = &players[PLAYER1];
      adversary_player = &players[PLAYER2];
   } else {
      current_player = &players[PLAYER2];
      adversary_player = &players[PLAYER1];
   }

   state = MENU;
}

// Performs the action in menu
void GameController::performMenuAction() {
   switch (action) {
      case SELECT:
         state = SELECT_PLAYERS;
         break;
      case INFORMATION:
         state = ABOUT;
         break;
      case QUIT:
         state = QUITTING;
         last_state = MENU;
         break;
      default:
         break;
   }
}

void GameController::createPlayer() {
   if (action == CREATE) {
      if (buffer_name == SELECT_MACHINE) {
         players[number_of_players] = Player(MACHINE, default_names[number_of_players]);
      } else {
         players[number_of_players] = Player(HUMAN, buffer_name);
      }

      ++number_of_players;
   }

   if ((number_of_players >= DEFAULT_NUMBERS_OF_PLAYERS && action == PLAY) ||
      number_of_players == MAXIMUM_NUMBER_OF_PLAYERS) 
   {
      state = PLAYING;
   } else {
      state = CREATE_PLAYERS;
   }
}

// Performs the action and modifies the situation
void GameController::performPlayerAction() {
   switch (action) {
   case ROLL:
      rollingDice();
      break;
   case HOLD:
      holdingScore();
      break;
   case QUIT:
      state = QUITTING;
      last_state = PLAYING;
      break;
   default:
      break;
   }
}

// Roll the dice
void GameController::rollingDice() {
   dice.roll();
   round_log.turns++;

   if (dice.getNumber() == PIG_DICE) {
      current_player->clearTurnScore();
      holdingScore();
   } else {
      current_player->addTurnScore(dice.getNumber());
      state = ROLLING;
   }
}

// Hold the current score
void GameController::holdingScore() {
   round_log.score = current_player->getTurnScore();
   current_player->addLog(round_log);
   clearRoundLog();

   current_player->addScore();

   state = HOLDING;
}

// Clear current log
void GameController::clearRoundLog() {
   round_log.turns = DEFAULT_ROUND;
   round_log.score = DEFAULT_SCORE;
}

// Check if there is a winner
void GameController::checkWinner() {
   current_player->clearTurnScore();

   if (current_player->getScore() >= WINNERS_SCORE) {
      winner = current_player;
      state = WINNER;
   } else {
      switchPlayer();
      state = PLAYING;
   }
}

// Change current player
void GameController::switchPlayer() {
   if (current_player == &players[PLAYER1]) {
      current_player = &players[PLAYER2];
      adversary_player = &players[PLAYER1];
   } else {
      current_player = &players[PLAYER1];
      adversary_player = &players[PLAYER2];
   }
}

// Checks if the game has ended
void GameController::verifyEnding() {
   if (action == END) {
      state = ENDING;
   } else {
      state = last_state;
   }
}

// Show main menu
void GameController::showMenu() const {
   cout << "\n\t---> Welcome to the Pig Dice Game (v 1.0) <---\n";
   cout << "\t\t-copyright DIMAp/UFRN 2023-\n\n\n";

   cout << "1. Select Players\n";
   cout << "2. About\n";
   cout << "Q. Quit\n";

   cout << "\n>>>Select an option: ";
}

void GameController::showCreatePlayer() const {
   cout << "\n-------------------------------------------------------\n";

   cout << "\nCreate " << number_of_players << "° player:\n";
   cout << "\tHuman player - Enter name (cannot \"Machine\")\n";
   cout << "\tMachine player - Enter with Machine (the name is automatic)\n";
   cout << "\tEnd - Press <enter>\n";

   cout << "\n>>> Write here: ";
}

// Show about section
void GameController::showAbout() const {
   cout << "\n-------------------------------------------------------\n";

   cout << "About the game: \n";
   cout << "\tThe object of the jeopardy dice game Pig is to be the first "
        << "player to reach 100 points.\n";
   cout << "\tEach player's turn consists of repeatedly rolling a die. After "
        << "each roll, the player is faced with two choices: roll again, or "
        << "hold (decline to roll again).\n";

   cout << "\t\t• If the player rolls a 1, the player scores nothing and it "
        << "becomes the opponent's turn.\n";
   cout
       << "\t\t• If the player rolls a number other than 1, the number is "
       << "added to the player's turn total and the player's turn continues.\n";
   cout
       << "\t\t• If the player holds, the turn total, the sum of the rolls "
       << "during the turn, is added to the player's score, and it becomes the "
       << "opponent's turn.\n\n";

   cout << "Motivation:\n";
   cout << "\tThe present software was developed for the submission of "
        << "assignments for the Programming I course at the Federal University "
        << "of Rio Grande do Norte.\n\n";

   cout << "About the development:\n";
   cout << "\tDeveloper: Pedro Lucas\n";
   cout << "\tE-mail: pedrolucas.jsrn@gmail.com\n";
   cout << "\tGithub: PedroLucas63\n\n";

   cout << "\tPress <Enter> to return.";
}

// Show players
void GameController::showPlayers() const {
   cout << "\n>>> The players of the game are: \"" << players[PLAYER1].getName()
        << "\" & \"" << players[PLAYER2].getName() << "\".\n\n";
   cout << ">>> The player who will start the game is \""
        << current_player->getName() << "\".\n";
}

// Show commands
void GameController::showCommands() const {
   cout << "\n-------------------------------------------------------\n";
   cout << ">>> The current player is: \"" << current_player->getName()
        << "\".\n\n";

   cout << "Commands syntax:\n";
   cout << "  <Enter>       -> ROLL the dice.\n";
   cout << "  'r' + <Enter> -> ROLL the dice.\n";
   cout << "  'h' + <Enter> -> HOLD (add turn total and pass turn over).\n";
   cout << "  'q' + <Enter> -> quit the match (no winner).\n\n";

   cout << "Enter command > ";
}

// Show turn score
void GameController::showTurnTotal() const {
   cout << "\n>>> Requested action: \"" << str_actions[action] << "\".\n";

   if (action == ROLL) {
      cout << "\tDice value is \"" << dice.getSymbol() << "\" ("
           << dice.getNumber() << ")\n";
   }

   cout << "\tThe turn total is: " << current_player->getTurnScore() << "\n";
}

// Show total score
void GameController::showScores() const {
   char const separator { ' ' };
   cout << std::setfill(separator);

   cout << "\n┌───────────────────────┐\n";
   cout << "│      Score Board      │\n";
   cout << "├───────────┬───────────┤\n";
   cout << "│" << std::setw(COLUMN_SIZE) << players[PLAYER1].getName() << "│"
        << std::setw(COLUMN_SIZE) << players[PLAYER1].getScore() << "│\n";
   cout << "│" << std::setw(COLUMN_SIZE) << players[PLAYER2].getName() << "│"
        << std::setw(COLUMN_SIZE) << players[PLAYER2].getScore() << "│\n";
   cout << "└───────────┴───────────┘\n";

   cout << ">>> Press enter to continue...";
}

// Displays the quitting confirmation
void GameController::showQuitting() const {
   cout << ">>> Requested action: \"" << str_actions[action] << "\".\n";
   cout << "Do you really want to end the game (Y/n) > ";
}

// Show winner
void GameController::showWinner() const {
   cout << "\nTHE WINNER IS \"" << winner->getName() << "\".\n\n";
}

// Show players log
void GameController::showLogs() const {
   cout << "[[ LOG of ACTIONS during the game ]]\n\n";

   cout << "Decisions taken by player \"" << players[PLAYER1].getName()
        << "\":\n";

   for (utils::RoundLog round : *players[PLAYER1].getLogs()) {
      cout << round.turns << " dice rolls produced " << round.score << "\n";
   }

   cout << "\nDecisions taken by player \"" << players[PLAYER2].getName()
        << "\":\n";

   for (utils::RoundLog round : *players[PLAYER2].getLogs()) {
      cout << round.turns << " dice rolls produced " << round.score << "\n";
   }
}

// Show ending
void GameController::showEnding() const {
   cout << "\n\t---> [ Thanks for playing. See you next time! ] <---\n\n";
}
