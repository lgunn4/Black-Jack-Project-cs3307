#pragma once
#include "InputMenu.h"

class Wallet
{
private:
    int funds;
    int currentBet;
    int startBet;
    int sideBet;
    
public:
    Wallet();
    ~Wallet();
    int & getFunds();
    void addFunds(int _funds);
    void removeFunds(int fundsToRemove);
    void newBet(int bet);
    void newStartBet(int Bet);
    int & getStartBet();
    int & getBet();
    int & getSideBet();
    void newSideBet(int bet);
    void refresh();
};

