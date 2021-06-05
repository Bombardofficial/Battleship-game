#include "Kreuzer.h"

bool Kreuzer::hasBombardment()
{
	return true;
}

void Kreuzer::ausSchreiben()
{
	std::cout << "Kreuzer";
	Schiff::ausSchreiben();
}
