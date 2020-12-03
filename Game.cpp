/**
* @class Game
* @author PengJu Chang, Yu Fan Chen , Logan Gunn , Everett Scott Melanson , William Zhen Yu Ngo
* @brief A class that stores attributes and methods specific to the entire game instance. Also allows the game to start.
*/
#include "Game.h"

/**
* @brief the constructor for the game class that initializes the dealer, number of decks used and the deck object.
*	@param _dealer
*			pointer to the dealer object.
*	@param _numDecks
*			number of decks to be used.
*/
Game::Game(Player *_dealer, int _numDecks)
{
    dealer = _dealer;
    numDecks = _numDecks;
    deck = Deck(numDecks);

}

/**
* @brief a method that adds a pointer to a Player object to the list of players.
*	@param value
*			Player pointer to a player object to be added to the list of players
*/
void Game::addPlayer(Player *value)
{
    playerList.push_back(value);
}

/**
* @brief a method that checks who won the current game
*/
void Game::winOrLose()
{
	//Loops through the list of players and checks whether the won or not.
    for (int i = 0; i < playerList.size(); i++)
    {
        Player *player = playerList.at(i);

        if (player->getSurrendered()) {
            printSurrender(player);
        }
        //If we bust we lose
        else if (player->bust())
        {
            printBust(player);

            //If dealer has blackjack we lose
        }
        else if (dealer->blackJack())
        {
            printLoose(player);

            //If we have blackjack we win
        }
        else if (player->blackJack())
        {
            printBlackJack(player);
            // If dealer busted we win
        }
        else if (!player->bust() && dealer->bust())
        {
            printWin(player);

            // If our hand is greater than the dealers we win
        }
        else if (player->handTotal() > dealer->handTotal())
        {
            printWin(player);
            // If our hand ties the dealer we push
        }
        else
        {
            printLoose(player);
        }
    }

    // Display the hand of the dealer
    if (dealer->blackJack())
    {
        printBlackJack(dealer);
    }
    else if (dealer->bust())
    {
        printBust(dealer);
    }
    else
    {
        std::cout << dealer->getName() << "'s hand total: " << dealer->handTotal() << std::endl;
    }
}

/**
* @brief a method that works out the winning of the player who won and adds it to the player's wallet.
*/
void Game::calculateBets()
{

    for (int i = 0; i < playerList.size(); i++)
    {
        Player *player = playerList.at(i);
      	//Checks that the player did not surrender, as that player will have no change to their wallet.
        if (!player->getSurrendered())
        {
            if (player->blackJack())
            {
                player->getWallet().addFunds(player->getWallet().getBet() * 2);
            }
            else if (!player->bust() && dealer->bust())
            {
                player->getWallet().addFunds(player->getWallet().getBet() * 2);
            }
            else if (player->handTotal() > dealer->handTotal() && !player->bust())
            {
                player->getWallet().addFunds(player->getWallet().getBet() * 2);
            }

            if (dealer->handTotal() == 21 && player->getWallet().getSideBet() > 0) {
                player->getWallet().addFunds(player->getWallet().getSideBet() * 2);
            }
        }
      	//Prints out the new wallet balance.
        std::cout << player->getName() << "'s new account balance is: " << player->getWallet().getFunds() << "\n";
    }
    std::cout << "\n";
}

/**
* @brief a method that starts the game.
*/
void Game::start()
{
    //Shuffles the deck.
    deck.shuffleDeck();

    //Distribute cards to players.
    for (int j = 0; j < 2; j++)
    {
        for (int i = 0; i < playerList.size(); i++)
        {
            playerList.at(i)->hitMe(deck);
        }
        dealer->hitMe(deck);
    }

    //Loops through list of players.
    for (int i = 0; i < playerList.size(); i++)
    {
        turn(playerList.at(i));
    }
    turn(dealer);
}

/**
* @brief a helper method that makes the player and dealer takes turns during the game
*	@param player
*			Player pointer to a player object
*/
void Game::turn(Player *player)
{
    std::cout << "\n"
              << player->getName() << "'s turn: " << std::endl;
    std::cout << player->getName() << "'s Hand: " << std::endl;
    player->printHand();

    bool dealerHasAce = false;
    for (int i = 0; i < dealer->getHand().size(); i++)
    {
        if (player->getHand().size() == 2 && dealer->getHand().at(i) == 11 && player->getWallet().getStartBet() > 0) {
            dealerHasAce = true;
        }
    }

    if (dealerHasAce) {
        bool decision = InputMenu::yesOrNoMenuChoice("The dealer has an ace. Would you like to take an insurance bet? (y/n)");
        if (decision)
        {
            player->insurance();
        }
    }

    while (!player->bust())
    {
        char playerChoice = tolower(player->choice());

        if (playerChoice == 'h')
        {
            player->hitMe(deck);
            std::cout << player->getName() << "'s Hand: " << std::endl;
            player->printHand();
        }
        else if (playerChoice == 's')
        {
            player->stand();
            break;
        }
        else if (playerChoice == 'c')
        {
            getHint(player); // should reloop back for player input again
        }
        else if (playerChoice == 'a')
        {
            int advancedChoice = InputMenu::advancedCallChoice();

            if (player->getHand().size() == 2)
            {
                if (advancedChoice == 'd')
                {
                    if (player->getWallet().getFunds() - player->getWallet().getStartBet() * 2 < 0) {
                        std::cout << "You do not have enough funds for Double Down" << std::endl;
                    } else {
                        player->doubleDown(deck);
                        std::cout << player->getName() << "'s Hand: " << std::endl;
                        player->printHand();
                        break;
                    }
                }

                if (advancedChoice == 's')
                {
                    player->surrender();
                    break;
                }
            }
            else
            {
                std::cout << "Call only avaliable on turn 1." << std::endl;
            }
        }
    }
}

/**
* @brief a method that prints the player's hand total if they have a blackjack.
*	@param player
*			Player pointer to a player object
*/
void Game::printBlackJack(Player *player)
{
    std::cout << player->getName() << "'s hand total: " << player->handTotal() << " --- BlackJack!" << std::endl;
}

/**
* @brief a method that prints the player's hand total if they bust.
*	@param player
*			Player pointer to a player object
*/
void Game::printBust(Player *player)
{
    std::cout << player->getName() << "'s hand total: " << player->handTotal() << " --- Bust!" << std::endl;
}

/**
* @brief a method that prints the player's hand total if they won without a blackjack.
*	@param player
*			Player pointer to a player object
*/
void Game::printWin(Player *player)
{
    std::cout << player->getName() << "'s hand total: " << player->handTotal() << " --- Win!" << std::endl;
}

/**
* @brief a method that prints the player's hand total if they lost.
*	@param player
*			Player pointer to a player object
*/
void Game::printLoose(Player *player)
{
    std::cout << player->getName() << "'s hand total: " << player->handTotal() << " --- Lose!" << std::endl;
}

/**
* @brief a method that allows the last game played to be played back in a replay.
*/
void Game::replay()
{
    for (auto player : playerList)
    {
        replayTurn(player);
    }
    replayTurn(dealer);

    winOrLose();
}

/**
* @brief a helper method goes through the hand of the current player and make them take their turns in the replay viewer.
*	@param player
*			Player pointer to a player object
*/
void Game::replayTurn(Player *player)
{
    std::cout << player->getName() << "'s turn:" << std::endl;

    int numCards = player->getHand().size();
    for (int i = 2; i <= numCards; ++i)
    {
        int total = getTurnTotal(player, i);
        std::cout << "Hand Total: " << total << std::endl;

        if (numCards == 2 && player->getWallet().getStartBet() * 2 == player->getWallet().getBet())
        {
            std::cout << "Hit, Stand or Advanced Call: "
                      << "a" << std::endl;
            std::cout << "Double Down (d), or Surrender(s)? "
                      << "d" << std::endl
                      << std::endl;
            break;
        }
        else if (numCards == i && player->getWallet().getStartBet() / 2 == player->getWallet().getBet())
        {
            std::cout << "Hit, Stand or Advanced Call: "
                      << "a" << std::endl;
            std::cout << "Double Down (d), or Surrender(s)? "
                      << "s" << std::endl
                      << std::endl;
            break;
        }
        else if (numCards > i)
        {
            std::cout << "Hit, Stand or Advanced Call: "
                      << "h" << std::endl;
        }
        else
        {
            std::cout << "Hit, Stand or Advanced Call: "
                      << "s" << std::endl
                      << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(2000)); //sleep for 2 seconds before the next move is displayed.
    }
}

/**
* @brief a method that returns the hand total on a specific turn with numCards number of cards in their hand.
*	@param player
*			Player pointer to a player object
*	@param numCards
*			number of cards in the player's hand currently
*/
int Game::getTurnTotal(Player *player, int numCards)
{
    int total = 0;
    int numAce = 0;
    std::vector<int> currentHand;

    for (int i = 0; i < numCards; ++i)
    {
        int card = player->getHand().at(i);
        currentHand.push_back(card);

        if (card == 11)
        {
            numAce++;
        }
        total = total + player->getHand().at(i);
    }
    if (total > 21 && numAce > 0)
    {
        for (int i = 0; i < numCards; ++i)
        {
            int card = player->getHand().at(i);

            if (card == 11 & total > 21)
            {
                total -= 10;
            }
        }
    }
    Deck::printCards(currentHand);
    return total;
}

Deck Game::getDeck() const
{
    return deck;
}

/**
* @brief a method that gives a hint to the player depending on dealer situation.
*	@param player
*			Player pointer to a player object
*/
void Game::getHint(Player *player)
{
    /**
   This function tells a player what to do based on their hand total and the dealer's
   hand total and behaviour.
    */

    int dealerTotal = dealer->handTotal();
    int playerTotal = player->handTotal();
    bool dealerIsStanding = false;
    int nextCard = deck.peek();

    if (dealerTotal > 17)
    { // first determine dealer behaviour
        dealerIsStanding = true;
    }

    // I apologize for this ugly code
    // Determine if player is winning or losing
    if (playerTotal > dealerTotal)
    {
        std::cout << "You are currently winning!" << std::endl;
    }
    else if (playerTotal == dealerTotal)
    {
        std::cout << "You and the dealer are tied!" << std::endl;
    }
    else
    {
        std::cout << "You are currently losing!" << std::endl;
    }

    // Tell player what to do based on their next draw

    // If player is unable to draw, determine the best option
    if (playerTotal + nextCard > 21)
    {
        std::cout << "Drawing the next card will bust you. ";
        if (playerTotal >= dealerTotal && dealerIsStanding)
        { // Guaranteed win/draw
            std::cout << "Stand!" << std::endl;
        }
        else
        { // Dealer could either bust or outdraw player in all other scenarios
            std::cout << "Surrender to play it safe, Stand if you feel lucky!"
                      << std::endl;
        }
    }
    else
    {
        // Pretty sure players can only double down on first turn?

        // In this case, player can safely double down
        if (playerTotal + nextCard >= dealerTotal && dealerIsStanding)
        {
            if (player->getHand().size() == 2)
            {
                std::cout << "Double down!" << std::endl;
            }
        }
        else
        {
            std::cout << "Hit!" << std::endl;
        }
    }
}

void Game::printSurrender(Player *player) {
    std::cout << player->getName() << "' surrendered " << "--- Get's half of bet back!" << std::endl;

}

/**
* @brief a method that resets the current game to the initial state.
*/
void Game::refreshGame() {
  	//resets all players to the initial state.
    for (auto player: playerList) {
        player->refresh();
    }
    dealer->refresh(); //resets the dealer to the initial state.
    deck = Deck(numDecks); //resets the deck to the initial state.
}

/**
* @brief a method that lets the player to choose how much money they want to bet provided they have enough funds in their wallet.
*/
void Game::getBets() {
    for (int i = 0; i < playerList.size(); ++i) {
        Player *player = playerList.at(i);
        std::cout << player->getName() << "'s Current Wallet Balance: $" << player->getWallet().getFunds() << ".00" << std::endl;

        if (player->getWallet().getFunds() == 0) {
            std::cout << player->getName() << " does not have enough funds to play and has been removed from the game!" << std::endl << std::endl;
            playerList.erase(playerList.begin() + i);
            --i;
        } else {
            player->getWallet().newStartBet(
                    InputMenu::intMenuChoice("How much money would " + player->getName() + " like to bet?"));
            player->getWallet().newBet(player->getWallet().getStartBet());
            while (player->getWallet().getFunds() < player->getWallet().getStartBet()) {
                std::cout << "Insufficent Funds. \n";
                player->getWallet().newStartBet(
                        InputMenu::intMenuChoice("How much money would " + player->getName() + " like to bet?"));
            }
            player->getWallet().removeFunds(player->getWallet().getStartBet());
        }
    }
}

std::vector<Player *> Game::getPlayerList() {
    return playerList;
}
