#include "Schiff.h"
#include <iostream>

using namespace std;

void Schiff::subtrahierenHulle(int schadencounter)
{
	this->hulle -= schadencounter;

}

int Schiff::getkonkretSchaden(int trefferprobe)
{
	return this->schaden;
}

int Schiff::trefferProbeModifikator()
{
	return 0;
}

bool Schiff::hasBombardment()
{
	return false;
}

void Schiff::ausSchreiben()
{
	cout << " Hulle: " << hulle << " / Grosse: " << grosse << " / Schaden: " << schaden << endl;
}
