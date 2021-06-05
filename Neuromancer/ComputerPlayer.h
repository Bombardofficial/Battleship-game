#pragma once
#include "player.h"
class ComputerPlayer :
    public player
{
public:
    ComputerPlayer(string name, Flotte* flotte, Flotte* enemyFlotte) : player(name, flotte, enemyFlotte) {
        flotte->generieren();
    }

    Schiff *getAttackerSchiff();
    Schiff *getDefenderSchiff();
};

