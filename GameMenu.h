#pragma once


#include "HumanPlayer.h"
#include "CustomDealer.h"
#include "Game.h"

class GameMenu {
    public:
        static Game * setUpGame();
        static bool finishGame(Game game);
};


