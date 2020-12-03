#pragma once


#include "Player.h"

class CustomDealer: public Player {
    private:
        int customMax;
    public:
        CustomDealer(int _customMax);
        char choice();
};