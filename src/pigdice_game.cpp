/*!
 * Game Controller implementation.
 *
 * \author Selan
 * \date March 23rd, 2022
 */
#include <algorithm>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <iterator>

#include "pigdice_common.h"
#include "pigdice_game.h"

// Just for debugging.
static std::string state_names[] = {
    "STARTING",
    "WELCOME",
    "PLAYING",
    "ROLLING",
    "HOLDING",
    "UPDATING SCORE",
    "QUITTING",
    "ENDING"
};

/// Action names
static const std::string action_names[] = { "Hold", "Roll", "Quit", "UnknowN" };
/// String representation for the dice's faces (Unicode).
static const std::string dice_faces[] = { "\u2680", "\u2681", "\u2682", "\u2683", "\u2684", "\u2685", "Undefined" };

void GameController::initialize()
{
    // -----------------------------------------------------------------------
    // Choosing between a "fixed" or ramdom dice.
    // -----------------------------------------------------------------------
    // [1]== Fixed seed, which means this dice generates the same sequence of numbers.
    //dice::set_seed( dice::seed_t::FIXED, 1 );
    // [2]== A random seed means the numbers produced by the dice ara random.
    dice::set_seed( dice::seed_t::RANDOM ); // Semente fixada em 1.
    // -----------------------------------------------------------------------

    // Create players
    m_players[player_e::MACHINE] = Player{"Macine"};
    m_players[player_e::HUMAN] = Player{"Jack"};
    // Reset turn total information: <scrore,# rolls>
    m_turn_total = TurnInfo{0,0};
    // No starting player defined just yet.
    m_player = player_e::UNDEFINED;
    // set current action.
    m_action = action_e::NONE;
    // No winner yet.
    m_winner = player_e::UNDEFINED;
    // Die undefined.
    m_face = dice_face_e::FACE_UNDEFINED;
    // Current game state.
    m_game_state = game_state_e::STARTING;
    // We do not want to quit just yet.
    m_asked_to_quit = false;
}

bool GameController::game_over(void) const
{
    return m_game_state == game_state_e::ENDING;
}

void GameController::process_events(void)
{
    if ( m_game_state == game_state_e::STARTING or
         m_game_state == game_state_e::ROLLING or
         m_game_state == game_state_e::HOLDING )
    {
        // Do nothing, no interaction in these states.
    }
    else if ( m_game_state == game_state_e::WELCOME )
    {
    }
    else if ( m_game_state == game_state_e::PLAYING )
    {
    }
    else if ( m_game_state == game_state_e::UPDATING_SCORE )
    {
    }
    else if ( m_game_state == game_state_e::QUITTING )
    {
    }
}

void GameController::update(void)
{
    if ( m_game_state == game_state_e::STARTING )
    {
        // Randomly choose who's going to start the match
        m_player = dice::roll(2); // heads or tails?
        m_game_state = game_state_e::WELCOME;
    }
    else if ( m_game_state == game_state_e::WELCOME )
    {
        // Go to PLAY state.
        m_game_state = game_state_e::PLAYING;
    }
    else if ( m_game_state == game_state_e::PLAYING )
    {
    }
    else if ( m_game_state == game_state_e::ROLLING )
    {
    }
    else if ( m_game_state == game_state_e::HOLDING )
    {
    }
    else if ( m_game_state == game_state_e::UPDATING_SCORE )
    {
    }
    else if ( m_game_state == game_state_e::QUITTING )
    {
    }
    else
    {
        // Do nothing in these states.
        //  + ENDING
    }
}

void GameController::render(void) const
{
    if ( m_game_state == game_state_e::STARTING )
    {
        // Do nothing in this state.
    }
    else if ( m_game_state == game_state_e::WELCOME)
    {
        // Welcome msg and rules.
        display_welcome_screen();
    }
    else if ( m_game_state == game_state_e::PLAYING )
    {
    }
    else if ( m_game_state == game_state_e::ROLLING)
    {
    }
    else if ( m_game_state == game_state_e::HOLDING )
    {
    }
    else if ( m_game_state == game_state_e::UPDATING_SCORE )
    {
    }
    else if ( m_game_state == game_state_e::ENDING )
    {
    }
    else if ( m_game_state == game_state_e::QUITTING )
    {
    }
}

bool GameController::read_user_confirmation() const
{
    auto STR_LOWERCASE = [](const char* t)->std::string
    {
        std::string str{ t };
        std::transform( str.begin(), str.end(), str.begin(), ::tolower );
        return str;
    };
    // Read a simple line with the command from user.
    std::string line;
    std::getline(std::cin,line); // Let us ignore any prepending white spaces.
    std::string low_line = STR_LOWERCASE(line.c_str());

    if ( low_line == "y" or low_line == "yes" or low_line == "ye" or low_line == "ys")
        return true;
    else return false;
}

