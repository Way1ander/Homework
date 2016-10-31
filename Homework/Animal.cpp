#include "stdafx.h"
#include "Animal.h"


Animal::Animal(int number, double chance, bool presence, int scores)
{
	Animal::number = number;
	Animal::presence = presence;
	Animal::chance = chance;
	Animal::scores = scores;
}

Animal::Animal()
{
	Animal::number = 0;
	Animal::chance = 0;
	Animal::presence = 0;
	Animal::scores = 0;
}

int Animal::setNumber(int number){
	if (number >= 0){
		Animal::number = number;
		return 0;
	}
	else return 1;//Неправильный формат
}

int Animal::getNumber(){
	return number;
}

int Animal::setPresence(bool presence){
	if (presence == 0 || presence == 1){
		Animal::presence = presence;
		return 0;
	}
	else return 1;//Неправильный формат
}

bool Animal::getPresence(){
	return presence;
}

int Animal::setChance(double chance){
	if (chance > 0 && chance <= 1){
		Animal::chance = chance;
		return 0;
	}
	else return 1;//Неправильный формат
}

double Animal::getChance(){
	return chance;
}

int Animal::setscores(int scores){
	if (scores > 0){
		Animal::scores = scores;
		return 0;
	}
	else return 1;//Неправильный формат
}

int Animal::getscores(){
	return scores;
}

Animal::~Animal()
{
}
