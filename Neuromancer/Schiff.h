#pragma once

class Schiff
{
protected:
	int hulle;
	int grosse;
	int schaden;

public:
	// Schiff *s = new Schiff(75, 4, 30);
	Schiff(int h, int g, int s) : hulle(h), grosse(g), schaden(s) {}
	int getGrosse() { return grosse; }
	int getHulle() { return hulle; }
	int getSchaden() { return schaden; }
	void subtrahierenHulle(int schadencounter);
	virtual int getkonkretSchaden(int trefferprobe);
	virtual int trefferProbeModifikator();
	virtual bool hasBombardment();
	virtual void ausSchreiben();
	virtual ~Schiff() {};
};
