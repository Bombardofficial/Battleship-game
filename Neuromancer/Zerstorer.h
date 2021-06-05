#pragma once
#include "Schiff.h"

class Zerstorer : public Schiff
{

public:
	Zerstorer() : Schiff(150, 6, 60) {}
	int trefferProbeModifikator();
	void ausSchreiben();
};
