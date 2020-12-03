#pragma once


#include "Deck.h"
#include "Player.h"
#include "InputMenu.h"

class HumanPlayer:public Player {
	public:
        HumanPlayer(std::string _name);
		char choice();
};
