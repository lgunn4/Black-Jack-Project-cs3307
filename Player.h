#pragma once


#include <vector>
#include "Deck.h"
#include "Wallet.h"
#include "InputMenu.h"

class Player {
    private:
        std::vector<int> currentHand;
        std::vector<char> handLetters;
        Wallet playerWallet;
        bool surrendered;

    protected:
        std::string name;

    public:
        Player();
        virtual ~Player();
        const std::vector<int> getHand() const;
        void hitMe(Deck &d);
        void stand();
        void doubleDown(Deck &d);
        void surrender();
        void insurance();
        void printHand();
        int handTotal();
        virtual char choice() = 0;
        int sum();
        std::string getName() const;
        bool bust();
        bool blackJack();
        Wallet & getWallet();
        bool getSurrendered();
        void refresh();
};