#pragma once
#include "Player.h"
#include "Dealer.h"
#include <fstream>
#include <thread>
#include <algorithm>

class Game {
	private:
		std::vector<Player*> playerList;
		Player *dealer;
		int numDecks;
		Deck deck;

    private:
        void turn(Player *player);
		static void printBlackJack(Player *player);
		static void printBust(Player *player);
		static void printWin(Player *player);
		static void printLoose(Player *player);
		static void printSurrender(Player *player);
		int getTurnTotal(Player *player, int numCards);
        void replayTurn(Player *player);
	public:
        explicit Game(Player *_dealer, int _numDecks);
        void refreshGame();
		void addPlayer(Player *value);
		void winOrLose();
		void calculateBets();
		void start();
		void replay();
        Deck getDeck() const;
		void getHint(Player *player);
		void getBets();
        std::vector<Player*> getPlayerList();

};

