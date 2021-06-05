#pragma once

#include <string>
#include <iostream>
#include <ctime>
#include <cctype>

#include "flotte.h"

//#include "board.h"

using namespace std;

class player
{
protected:
	string name;
	Flotte *flotte;
	Flotte *enemyFlotte;
public:
	player(string name, Flotte* flotte, Flotte* enemyFlotte) :name(name), flotte(flotte), enemyFlotte(enemyFlotte) {}
	virtual Schiff *getAttackerSchiff() = 0; 
	virtual Schiff *getDefenderSchiff() = 0;
	Flotte* getFlotte() { return flotte; }
	Flotte* getEnemyFlotte() { return enemyFlotte; }
	string getName() { return name; }
};

