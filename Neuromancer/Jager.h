#pragma once
#include "Schiff.h"

class Jager : public Schiff
{
public:
	Jager() : Schiff(75, 4, 30) {}


	int getkonkretSchaden(int trefferprobe);

	void ausSchreiben();

};

