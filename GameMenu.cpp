#include "GameMenu.h"

/**
 * @author PengJu Chang, Yu Fan Chen , Logan Gunn , Everett Scott Melanson , William Zhen Yu Ngo
 * @class GameMenu
 * @brief A static class to represent the Game Menu
 * @details provides static methods for the main function to get user input regarding the game
 */


/**
 * @brief setUpGame - sets up Game for the main
 * @details takes in user input regarding the settings for the black jack game
 * @return Game that is specified by user input
 */
Game * GameMenu::setUpGame() {
    Player *dealer = new Dealer();
    int numPlayers = 1;
    int numDecks = 1;


    std::cout << "Standard Settings: 1 Player, 1 Deck, Normal Dealer Behaviour (Hit on 17 or lower)"
              << std::endl;
    if (InputMenu::yesOrNoMenuChoice("Would you like to change these settings? (y/n): ")) {
        numDecks = InputMenu::intMenuChoice("Enter the number of decks you would like to play with: ");
        numPlayers = InputMenu::intMenuChoice("Enter the number of players you would like to play with: ");
        bool customDealer = InputMenu::yesOrNoMenuChoice("Would you like to play with a customized dealer? (y/n): ");

        if (customDealer) {
            int customDealerSetting = InputMenu::intMenuChoice(
                    "Enter the number which you would like the dealer to not hit past: ");
            dealer = new CustomDealer(customDealerSetting);
        }
    }


    dealer->getWallet().newStartBet(-1);
    Game *newGame = new Game(dealer, numDecks);

    for (int i = 0; i < numPlayers; i++) {
        std::string playerName = "Player " + std::to_string(i + 1);
        Player *player = new HumanPlayer(playerName);
        newGame->addPlayer(player);
    }
    newGame->getBets();
    return newGame;
}

/**
 * @brief finishGame - ends the Game for the main
 * @param game the completed game
 * @details takes in a Game object and provides user input regarding options for when the game is finished
 *          and returns a bool for if player wants to play again
 * @return bool true if user wants to play again, and false if user quits
 */
bool GameMenu::finishGame(Game game) {
    bool endGameMenu = true;
    while (endGameMenu) {
        char choice = InputMenu::optionalMenuChoice(
                "Would you like to Reveal the deck? (d), watch a replay of the last game? (r), play again? (p), or quit? (q)",
                {'d', 'r', 'p', 'q'});

        if (choice == 'd') {
            game.getDeck().printDeckCards();
        } else if (choice == 'r') {
            game.replay();
        } else if (choice == 'p') {
            return true;
        } else {
            return false;
        }
    }
    return false;
}