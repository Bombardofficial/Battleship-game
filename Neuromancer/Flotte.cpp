#include "Flotte.h"
#include "jager.h"
#include "Kreuzer.h"
#include "Zerstorer.h"
#include <iostream>

using namespace std;

// Der Computer generiert eine Flotte für sich selbst
void Flotte::generieren()
{
	for (int i=0; i < 9; i++) {
		int wsch = rand() % 3;
		switch (wsch)
		{
		case 0:
			addierenSchiff(new Jager());
			break;
		case 1:
			addierenSchiff(new Zerstorer());
			break;
		case 2:
			addierenSchiff(new Kreuzer());
			break;

		default:
			break;
		}
	}
}
// Wir stellen die Flotte zusammen
void Flotte::chooseflotte()
{
	int flottenumber=1;
	for (int i = 0; i < 9; i++) {
		int chooseship;
		do {
			std::cout << flottenumber << ". (1)Jager, (2)Zerstorer or (3)Kreuzer?" << endl;
			std::cin >> chooseship;
			switch (chooseship)
			{
			case 1:
				addierenSchiff(new Jager());
				break;
			case 2:
				addierenSchiff(new Zerstorer());
				break;
			case 3:
				addierenSchiff(new Kreuzer());
				break;

			default:
				std::cout << "Invalid choose. Try again!" << endl;
				break;
			}
		} while (chooseship != 1 && chooseship != 2 && chooseship != 3);
		flottenumber++;
	}
}

void Flotte::addierenSchiff(Schiff* s)
{
	schiffs.push_back(s);
}

void Flotte::ausSchreiben()
{
	
	cout << "Flotte: \n" << endl;
	for (int i = 0; i < schiffs.size(); i++) {
		std::cout << i+1 << ". ";
		schiffs[i]->ausSchreiben();
	}

	cout << "___________________________________________" << endl;

}

// cnt: 1 ist die Seriennummer des ersten Schiffes
Schiff* Flotte::bekommenSchiff(int cnt)
{
	return schiffs[cnt-1];
}

void Flotte::loschenSchiff(Schiff *s)
{
	int index = -1;
	for (int i = 0; i < schiffs.size(); i++) {
		if (schiffs[i] == s) {
			index = i;
		}
	}
	if (index != -1) {
		schiffs.erase(schiffs.begin() + index, schiffs.begin() + index + 1);
	}
}

int Flotte::nummer() {
	return schiffs.size();
}

Flotte::~Flotte()
{
	for (int i = 0; i < schiffs.size(); i++) {
		delete schiffs[i];
	}
}
