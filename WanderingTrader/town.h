#pragma once

#include <iostream>
#include <string>

#include "item.h"

using namespace std;

class Town
{
public:
	Town(string name, float xCoord, float yCoord);

	string getName();
	float getXCoord();
	float getYCoord();
	int getDistance(float currentX, float currentY);

private:
	string selfName;
	float selfXCoord; // coordinate scale from 0 - 1 representing position on the map
	float selfYCoord; // ^
};

