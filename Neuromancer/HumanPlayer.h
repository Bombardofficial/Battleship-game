#pragma once
#include "player.h"
class HumanPlayer :
    public player
{
public:
    HumanPlayer(string name, Flotte* flotte, Flotte* enemyFlotte) : player(name, flotte, enemyFlotte) {
        flotte->chooseflotte();
    }

    Schiff* getAttackerSchiff();
    Schiff* getDefenderSchiff();
};

