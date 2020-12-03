#include <iostream>
#include <string>
#include "Game.h"
#include "GameMenu.h"

int main() {

	std::string replayPath;
	bool mainMenu = true;

    while (mainMenu) {
        Game *newGame = GameMenu::setUpGame();
        bool playAgain = true;


        while (playAgain && newGame->getPlayerList().size() > 0) {
            newGame->start();
            newGame->winOrLose();
            newGame->calculateBets();
            std::cout << std::endl;

            playAgain = GameMenu::finishGame(*newGame);
            if (playAgain) {
                newGame->refreshGame();
                newGame->getBets();
            }

        }
        mainMenu = InputMenu::optionalMenuChoice("Set up a new game (n) or quit (q)", {'n','q'}) == 'n';

    }
	return 0;
}