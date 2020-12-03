/**
* @class Player
* @author PengJu Chang, Yu Fan Chen , Logan Gunn , Everett Scott Melanson , William Zhen Yu Ngo
* @brief A class that stores attributes and methods specific to the Player
*/
#include "Player.h"

/**
* @brief destructor for Player
*/
Player::~Player() {
}

/**
* @brief constructor for the player
*/
Player::Player() {
    name = "Player";
    Wallet playerWallet;
    surrendered = false;
}

/**
* @brief returns the wallet for the player
*	@return playerWallet
*/
Wallet& Player::getWallet(){
    return playerWallet;
}

/**
* @brief returns current hand of cards for the player
*	@return currentHand
*/
const std::vector<int> Player::getHand() const {
    return currentHand;
}

/**
* @brief Draws one card for the player from the deck
*/
void Player::hitMe(Deck &d){
    currentHand.push_back(d.drawCard());
}

/**
* @brief allows the player to stand. i.e. does nothing.
*/
void Player::stand() {
    //Stand, so do nothing
}

/**
* @brief Allows the player to double down, which doubles the bet and draws a card.
*/
void Player::doubleDown(Deck &d){
    playerWallet.removeFunds(playerWallet.getStartBet());
    playerWallet.newBet(playerWallet.getStartBet()*2);
    currentHand.push_back(d.drawCard());
}

/**
* @brief Allows the player to surrender and only lose half of the initial bet.
*/
void Player::surrender(){
    playerWallet.newBet(playerWallet.getStartBet()/2);
    playerWallet.addFunds(playerWallet.getStartBet()/2);
    surrendered = true;

}

/**
* @brief Halves the side bet
*/
void Player::insurance(){
    if (playerWallet.getFunds() - playerWallet.getStartBet() * 1.5 < 0) {
        std::cout << "You do not have enough funds for insurance!" << std::endl;
    } else {
        playerWallet.newSideBet(playerWallet.getStartBet() * 0.5);
        playerWallet.removeFunds(playerWallet.getSideBet());
    }
}

/**
* @brief Prints all cards in the hand in number format as well as the hand total.
*/
void Player::printHand(){
    Deck::printCards(getHand());
    std::cout << "Hand total: " << handTotal() << std::endl;

}

/**
* @brief returns the total value of the player's hand after considering the value of ace
*	@return hand total after considering value of ace.
*/
int Player::handTotal() {
    int handTotal = sum();

    for (auto card: getHand()) {
        if (card == 11 && handTotal > 21) {
            handTotal -= 10;
        }
    }

    return handTotal;
}

/**
* @brief Sums together all cards in the player's hand and returns the total.
*	@return the current total of the hand, without considering ace values.
*/
int Player::sum() {
    int sum = 0;
    for (int i = 0; i < currentHand.size(); i++) {
        sum = sum + currentHand.at(i);
    }
    return sum;
}

/**
* @brief returns the name of the player
*	@return name
*/
std::string Player::getName() const {
    return name;
}

/**
* @brief returns a boolean value that represents whether or not the player bust
*	@return true if hand total is large than 21, otherwise false.
*/
bool Player::bust() {
    return handTotal() > 21;
}

/**
* @brief returns a boolean value that represents whether or not the player got a blackjack
*	@return true if hand total is 21 and only 2 cards, false otherwise.
*/
bool Player::blackJack() {
    return handTotal() == 21 && getHand().size() == 2;
}

/**
* @brief returns a boolean value that represents whether or not the player surrendered.
*	@return true if surrended, false otherwise.
*/
bool Player::getSurrendered() {
    return surrendered;
}

/**
* @brief resets the current player to initial state (state when the player was first created)
*/
void Player::refresh() {
    currentHand = {};
    surrendered = false;
    handLetters = {};
    getWallet().refresh();
}
