#include "HumanPlayer.h"

/**
 * @class HumanPlayer
 * @author PengJu Chang, Yu Fan Chen , Logan Gunn , Everett Scott Melanson , William Zhen Yu Ngo
 * @brief humanPlayer for the black jack game, implements abstract Player class
 **/

/**
 * @brief HumanPlayer - constructor for HumanPlayer class
 * @details sets the name for this object to parameter _name
 * @param _name - name of this object
 */
HumanPlayer::HumanPlayer(std::string _name) {
    name = _name;
}

/**
 * @brief choice - implements virtual Player method choice
 * @details using InputMenu static method standardCallChoice
 *          it gets user input for whether human player will hit or stand
 * @return 'h' for hit, 's' for stand, 'a' for advanced call
 */
char HumanPlayer::choice() {
    return InputMenu::standardCallChoice();
}

