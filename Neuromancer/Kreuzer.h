#pragma once
#include "Schiff.h"
#include <iostream>

class Kreuzer : public Schiff
{

public:
	Kreuzer() : Schiff(250, 8, 50) {}
	bool hasBombardment();
	void ausSchreiben();
};

