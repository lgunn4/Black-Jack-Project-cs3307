#pragma once


#include <vector>
#include <iostream>
#include <algorithm>
#include <random>

class Deck {
	private:
		std::vector<int> deck;
	public:
		Deck();
		Deck(int numDecks);
		const std::vector<int> getDeck() const;
		void setDeck(std::vector<int> newDeck);
		void shuffleDeck();
		void printDeck();
		void printDeckCards();
		bool isEmpty();
		int drawCard();
		int deckSize();
        static void printCards(std::vector<int> cards);
		int peek();
};

