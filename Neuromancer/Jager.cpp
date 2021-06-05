#include "Jager.h"
#include <iostream>

int Jager::getkonkretSchaden(int trefferprobe)
{
	if (trefferprobe >= 9)
	{
		return this->schaden * 2;
	}
	else
	{
		return this->schaden;
	}
}

void Jager::ausSchreiben() {
	std::cout << "Jager";
	Schiff::ausSchreiben();
}