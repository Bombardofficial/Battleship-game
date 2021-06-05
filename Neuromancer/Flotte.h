#pragma once
#include <vector>
#include "Schiff.h"

class Flotte
{
	std::vector<Schiff*> schiffs;
public:
	void playergame();
	void comgame();
	void generieren();
	void chooseflotte();
	void addierenSchiff(Schiff* s);
	void deleteSchiff(Schiff* s);
	void ausSchreiben(); // sorsz�mmal!
	Schiff* bekommenSchiff(int cnt);
	void loschenSchiff(Schiff *s);
	int nummer();
	~Flotte();
};

