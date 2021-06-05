#include "Zerstorer.h"
#include <iostream>

int Zerstorer::trefferProbeModifikator()
{
	return 2;
}

void Zerstorer::ausSchreiben()
{
	std::cout << "Zerstorer";
	Schiff::ausSchreiben();
}
