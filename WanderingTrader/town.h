#pragma once

#include <iostream>
#include <string>

#include "item.h"

using namespace std;

class Town
{
public:
	Town(string name, float xCoord, float yCoord, Item::EconomyTypes townRequires, Item::EconomyTypes townProduces);

	string getName();
	float getXCoord();
	float getYCoord();
	int getDistance(float currentX, float currentY);

	Item::EconomyTypes getRequired();
	Item::EconomyTypes getProduced();


private:
	string selfName;
	float selfXCoord; // coordinate scale from 0 - 1 representing position on the map
	float selfYCoord; // ^

	Item::EconomyTypes selfRequires;
	Item::EconomyTypes selfProduces;
};

