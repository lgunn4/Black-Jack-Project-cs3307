/**
* @class Deck
* @author PengJu Chang, Yu Fan Chen , Logan Gunn , Everett Scott Melanson , William Zhen Yu Ngo
* @brief A class that stores attributes and methods specific to the Deck.
*/
#include "Deck.h"

/**
* @brief constructor for the deck that initializes the single deck vector.
*/
Deck::Deck()
{
	deck = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
}

/**
* @brief constructor for the deck that initializes the deck vector to store numDecks number of decks.
*	@param numDecks
*			number of decks to store.
*/
Deck::Deck(int numDecks) {
	for (int i = 0; i < numDecks; i++) {
		std::vector<int> tempDeck = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10,
		11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11, 2, 3, 4, 5, 6, 7, 8, 9,
		10, 10, 10, 10, 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};

		deck.insert(deck.end(), tempDeck.begin(), tempDeck.end()); //Stores the tempDeck at the end of the current deck vector.

	}
}

/**
* @brief returns the size of the deck.
*	@return deck size.
*/
int Deck::deckSize() {
	return deck.size();
}

/**
* @brief returns the deck vector.
*	@return deck vector.
*/
const std::vector<int> Deck::getDeck() const
{
	return deck;
}

/**
* @brief sets the deck vector to newDeck.
*	@param newDeck - the new deck to bet set to deck vector.
*/
void Deck::setDeck(std::vector<int> newDeck)
{
	deck = newDeck;
}

/**
* @brief a method that shuffles the deck vector
*/
void Deck::shuffleDeck()
{
	std::shuffle(deck.begin(), deck.end(), std::random_device());
}

/**
* @brief prints the deck in the form of integer values of the cards.
*/
void Deck::printDeck()
{
	for (int i = 0; i < deck.size(); i++)
	{
		if (i % 10 != 0 || i == 0)
		{
			std::cout << deck.at(i) << ", ";
		}
		else
		{
			std::cout << deck.at(i) << std::endl;
		}
	}
	std::cout << "\n"
			  << std::endl;
}

/**
* @brief returns the boolean that represents whether or not the deck is empty.
*	@return true if the deck vector is empty, false otherwise.
*/
bool Deck::isEmpty()
{
	return (deck.size() == 0);
}

/**
* @brief removes one card from the front of the deck vector and returns that value.
*	@return first card values of the deck vector.
*/
int Deck::drawCard()
{
	int cardValue = deck[0];
	deck.erase(deck.begin());
	return cardValue;
}

/**
* @brief prints the deck in a text-based image format
*/
void Deck::printDeckCards()
{
	printCards(deck);
}

/**
* @brief helper method to print the deck in a text-based image format
*/
void Deck::printCards(std::vector<int> cards)
{
    int cardsPerLine = 8;	//sets the number of cards printed per line.
    int cardsPrinted = 0;	//number of cards printed so far
    int cardsRemaining = cards.size();

    while (cardsRemaining > 0)
    {
        if (cardsRemaining > cardsPerLine) {
            cardsPerLine = cardsPerLine;	// do nothing
        }
        else {
            cardsPerLine = cardsRemaining;
        }
        for (int i = cardsPrinted; i < cardsPrinted + cardsPerLine; i++)
        {

            std::cout << " ------     ";
        }
        std::cout << std::endl;

        //Prints the first line of the card with the value.
        for (int i = cardsPrinted; i < cardsPrinted + cardsPerLine; i++)
        {


            if (cards.at(i) > 1 && cards.at(i) < 10)
            {
                std::cout << "|" << cards.at(i) << "     "
                          << "|    ";
            }
            else if (cards.at(i) == 10)
            {
                std::cout << "|" << cards.at(i) << "    "
                          << "|    ";
            }
            else if (cards.at(i) == 1 || cards.at(i) == 11)
            {
                std::cout << "|"
                          << "A"
                          << "     "
                          << "|    ";
            }
        }
        std::cout << std::endl;

        //Prints middle lines of the card
        for (int i = 0; i < 3; i++)
        {
            for (int i = cardsPrinted; i < cardsPrinted + cardsPerLine; i++)
            {
                std::cout << "|"
                          << "      "
                          << "|    ";
            }
            std::cout << std::endl;
        }

        //Prints final line of the card with value.
        for (int i = cardsPrinted; i < cardsPrinted + cardsPerLine; i++)
        {
            if (cards.at(i) > 1 && cards.at(i) < 10)
            {
                std::cout << "|     " << cards.at(i) << "|    ";
            }
            else if (cards.at(i) == 10)
            {
                std::cout << "|    " << cards.at(i) << "|    ";
            }
            else if (cards.at(i) == 1 || cards.at(i) == 11)
            {
                std::cout << "|     "
                          << "A"
                          << "|    ";
            }
        }
        std::cout << std::endl;

        //Prints bottom of the card.
        for (int i = cardsPrinted; i < cardsPrinted + cardsPerLine; i++)
        {
            std::cout << " ------     ";
        }
        std::cout << std::endl;

        // update the number of cards we have printed and still need to print
        cardsPrinted = cardsPrinted + cardsPerLine;
        cardsRemaining = cardsRemaining - cardsPerLine;
    }
}

/**
* @brief a method that peeks at the top of the deck
* return the value of the card at the front of the deck vector.
*/
int Deck::peek() {
    return deck[0];
}
