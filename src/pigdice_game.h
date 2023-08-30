#ifndef _PIG_DICE_GAME_H_
#define _PIG_DICE_GAME_H_

#include <string>     // std::string
#include <array>
#include <memory>

#include "pigdice_common.h"
#include "player.h"
#include "dice.h"

/*!
 * This class represents the Game Controller which keeps track of player,
 * scores, and turn total values, as well as determining when a match ends.
 */
class GameController{
    private:
        //=== Structs
        //!< Possible game states.
        enum class game_state_e : uint {
            STARTING=0,          //!< Beginning the game.
            WELCOME,             //!< Opening messasges.
            PLAYING,             //!< Where the game action takes place.
            ROLLING,             //!< We roll the dice to get a face number.
            HOLDING,             //!< User asked to hold and pass turn to the next player.
            UPDATING_SCORE,      //!< Update the score board and show command issued in the turn.
            QUITTING,            //!< User might want to quit (before game finishes), need to confirm.
            ENDING,              //!< Closing the game (final message).
        };

        //=== Data members
        Player m_players[N_PLAYERS]; //!< List of players.
        bool m_asked_to_quit;        //!< Flag that indicates whether the user wants to end an ongoing game.
        size_t m_player;             //!< Index of the player of the turn.
        action_e m_action;           //!< Action chosen by the current player.
        dice::FaceType m_face;       //!< Curren face.
        TurnInfo m_turn_total;       //!< Current turn score <pts, # of times dice has been rolled>/
        game_state_e m_game_state;   //!< Current game state.
        size_t m_winner;             //!< Index of the winner.

    public:
        GameController()=default;
        GameController(const GameController&) = delete;
        GameController(GameController&&) = delete;
        GameController& operator=(const GameController&) = delete;
        GameController& operator=(GameController&&) = delete;
        ~GameController() = default;

        //=== Common methods for the Game Loop design pattern.
        void initialize(void);
        /// Renders the game to the user.
        void render(void) const;
        /// Update the game based on the current game state.
        void update(void);
        /// Process user input events, depending on the current game state.
        void process_events(void);
        /// Returns true when the user wants to quit the game.
        bool game_over(void) const;

    private:
        // === These read_xxx() methods are called in process_events()
};
#endif
