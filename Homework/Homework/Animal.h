#pragma once
#include "stdafx.h"

class Animal
{
private:
	int number;
	double chance;
	bool presence;
	int scores;
public:
	Animal();
	Animal(int number, double chance, bool presence, int scores);
	int setNumber(int number);
	int getNumber();
	int setChance(double chance);
	double getChance();
	int setPresence(bool presence);
	bool getPresence();
	int setscores(int scores);
	int getscores();
	~Animal();
};