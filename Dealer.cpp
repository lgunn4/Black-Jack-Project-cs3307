#include "Dealer.h"

/**
 * @class Dealer
 * @author PengJu Chang, Yu Fan Chen , Logan Gunn , Everett Scott Melanson , William Zhen Yu Ngo
 * @brief Dealer for the black jack game, implements abstract Player class
 * @details hits on a 17 or lower
 **/


/**
 * @brief Constuctor for Dealer class
 * @details sets the name the "Dealer"
 */
Dealer::Dealer() {
    name = "Dealer";
}

/**
 * @brief implements virtual Player method choice()
 * @details hits if handTotal is less than 17 and stands otherwise
 * @return char 'h' or 's' (hit or stand)
 */
char Dealer::choice() {
    if(this->handTotal() > 17) {
        return 's';
    }
    return 'h';
}
