#include "Wallet.h"


/**
 * @class Wallet
 * @author PengJu Chang, Yu Fan Chen , Logan Gunn , Everett Scott Melanson , William Zhen Yu Ngo
 * @brief represents player's wallet in black jack game
 */

Wallet::Wallet(){
    funds = 1000;
    currentBet = 0;
    startBet = 0;
    sideBet = 0;
}

/**
 * @biref getFunds - returns funds
 * @return int
 */
int& Wallet::getFunds(){
    return funds;
}

/**
 * @brief addFunds - adds funds
 * @param fundsToAdd - int to add to funds
 */
void Wallet::addFunds(int fundsToAdd){
    funds += fundsToAdd;
}

/**
 * @brief removeFunds - removes funds
 * @param fundsToRemove - int to remove from funds
 */
void Wallet::removeFunds(int fundsToRemove){
    funds -= fundsToRemove;
}

/**
 * @brief newBet - sets currentBet
 * @param bet - int to set currentBet to
 */
void Wallet::newBet(int bet){
    currentBet = bet;
}

/**
 * @brief getBet - gets currentBet
 * @return int - currentBet
 */
int& Wallet::getBet(){
    return currentBet;
}

/**
 * @brief newStartBet - sets startBet
 * @param bet - int to set to startBet
 */
void Wallet::newStartBet(int bet){
    startBet = bet;
}

/**
 * @brief getStartBet - gets startbet
 * @return int - startBet
 */
int& Wallet::getStartBet(){
    return startBet;
}

/**
 * @brief newSideBet - sets sideBet
 * @param bet - int to set sideBet
 */
void Wallet::newSideBet(int bet){
    sideBet = bet;
}

/**
 * @brief getSideBet - gets sideBet
 * @return int - sideBet
 */
int& Wallet::getSideBet(){
    return sideBet;
}

Wallet::~Wallet(){
}

/**
 * @brief refresh sets all bets to 0
 * @return void
 */
void Wallet::refresh() {
    currentBet = 0;
    startBet = 0;
    sideBet = 0;
}
