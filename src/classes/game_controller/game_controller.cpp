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
   "Rool", "Hold", "Quit", "End", "None",
};

// Constructor
GameController::GameController() { }
// Destructor
GameController::~GameController() { }

// Initialize game controller information
void GameController::initialize(std::string player_name) {
   players[HUMAN] = Player(player_name);
   players[MACHINE] = Player(DEFAULT_MACHINE_NAME);
   current_player = nullptr;
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
   case WELCOME:
      pressEnter();
      break;
   case PLAYING:
      getPlay();
      break;
   case UPDATING_SCORE:
      pressEnter();
      break;
   case QUITTING:
      confirmQuiting();
      break;
   default:
      break;
   }
}

// Update the states
void GameController::update() {
   switch (state) {
   case STARTING:
      current_player = &players[utils::rand(1)];
      state = WELCOME;
      break;
   case WELCOME:
      state = PLAYING;
      break;
   case PLAYING:
      performAction();
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
   case WELCOME:
      showMenu();
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
   std::getchar();
}

// Defines the player and move
void GameController::getPlay() {
   if (current_player == &players[HUMAN]) {
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
   bool roll { decideRoll(players[MACHINE], players[HUMAN]) };

   if (roll) {
      action = ROLL;
   } else {
      action = HOLD;
   }
}

// Receive confirmation of departure
void GameController::confirmQuiting() {
   std::string confirm;

   std::getline(std::cin, confirm);

   confirm = std::tolower(*confirm.begin());

   if (confirm == KEY_CONFIRM) {
      action = END;
   }
}

// Performs the action and modifies the situation
void GameController::performAction() {
   switch (action) {
   case ROLL:
      rollingDice();
      break;
   case HOLD:
      holdingScore();
      break;
   case QUIT:
      state = QUITTING;
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
   if (current_player == &players[HUMAN]) {
      current_player = &players[MACHINE];
   } else {
      current_player = &players[HUMAN];
   }
}

// Checks if the game has ended
void GameController::verifyEnding() {
   if (action == END) {
      state = ENDING;
   } else {
      state = PLAYING;
   }
}

// Show main menu
void GameController::showMenu() const {
   cout << "\t\t---> Welcome to the Pig Dice Game (v 1.0) <---\n";
   cout << "\t\t\t-copyright DIMAp/UFRN 2023-\n\n";

   cout << "The object of the jeopardy dice game Pig is to be the first "
        << "player to reach 100 points.\n";
   cout << "Each player's turn consists of repeatedly rolling a die. After "
        << "each roll, the player is faced with two choices: roll again, or "
        << "hold (decline to roll again).\n";

   cout << "\t• If the player rolls a 1, the player scores nothing and it "
        << "becomes the opponent's turn.\n";
   cout
       << "\t• If the player rolls a number other than 1, the number is "
       << "added to the player's turn total and the player's turn continues.\n";
   cout
       << "\t• If the player holds, the turn total, the sum of the rolls "
       << "during the turn, is added to the player's score, and it becomes the "
       << "opponent's turn.\n\n";

   cout << ">>> The players of the game are: \"" << players[HUMAN].getName()
        << "\" & \"" << players[MACHINE].getName() << "\".\n\n";
   cout << ">>> The player who will start the game is \""
        << current_player->getName() << "\".\n";

   cout << "\tPress <Enter> to start the match.";
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
   cout << "│" << std::setw(COLUMN_SIZE) << players[HUMAN].getName() << "│"
        << std::setw(COLUMN_SIZE) << players[HUMAN].getScore() << "│\n";
   cout << "│" << std::setw(COLUMN_SIZE) << players[MACHINE].getName() << "│"
        << std::setw(COLUMN_SIZE) << players[MACHINE].getScore() << "│\n";
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

   cout << "Decisions taken by player \"" << players[HUMAN].getName()
        << "\":\n";

   for (utils::RoundLog round : *players[HUMAN].getLogs()) {
      cout << round.turns << " dice rolls produced " << round.score << "\n";
   }

   cout << "\nDecisions taken by player \"" << players[MACHINE].getName()
        << "\":\n";

   for (utils::RoundLog round : *players[MACHINE].getLogs()) {
      cout << round.turns << " dice rolls produced " << round.score << "\n";
   }
}

// Show ending
void GameController::showEnding() const {
   cout << "\n\t---> [ Thanks for playing. See you next time! ] <---\n\n";
}
