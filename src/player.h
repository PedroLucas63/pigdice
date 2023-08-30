#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <cstddef>
#include <string>
#include <vector>
#include <string_view>
#include <iostream>

#include "pigdice_common.h"

/// Representing a single player.
class Player {
    private:
        std::string m_name; //!< The player's name
        std::vector<TurnInfo> m_turns_log; //!< List of turn total the player received in the match.
                                           //
    public:
        Player(std::string n) : m_name{n}
        {/*empty*/}
        /// Dtro
        ~Player() = default;
        /// Returns the player decision (action).
        action_e next_action();
        /// Returns the player's name
        std::string name(void) const;
        /// Returns the player's log of turn total s/he's won so far in the match.
        std::vector<TurnInfo> get_turns_log(void) const;
        /// Add a turn value to the player's log.
        void add_turn_total(const TurnInfo&);
        /// Return the player's current score.
        ScoreType get_score(void) const;
};

#endif
