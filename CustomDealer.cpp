#include "CustomDealer.h"

/**
 * @class CustomDealer
 * @author PengJu Chang, Yu Fan Chen , Logan Gunn , Everett Scott Melanson , William Zhen Yu Ngo
 * @brief custom dealer for the black jack game, implements abstract Player class
 * @details takes in input of a maximum it is allowed to hit on
 *          (in normal blackjack a dealer must hit on a 17 or lower)
 **/

/**
 * @brief Constructor for CustomDealer class
 * @details sets the name and the custom max for the CustomDealer object
 * @param _customMax - max number customDealer is allowed to hit on
 */
CustomDealer::CustomDealer(int _customMax) {
    name = "Custom Dealer";
    customMax = _customMax;
}

/**
 * @brief implements virtual Player method choice()
 * @details returns 'h' or 's' depending on what the CustomDealer's logic was initialized as
 * @return char 'h' or 's' (hit or stand)
 */
char CustomDealer::choice() {
    if(this->handTotal() > customMax) {
        return 's';
    }
    return 'h';
}
