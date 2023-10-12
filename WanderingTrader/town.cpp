#include "town.h"

Town::Town(string name, float xCoord, float yCoord, Item::EconomyTypes townRequires, Item::EconomyTypes townProduces) :
	selfName(name),
	selfXCoord(xCoord),
	selfYCoord(yCoord),
	selfRequires(townRequires),
	selfProduces(townProduces){
	// here goes the rest of a constructor
}

string Town::getName() {
	return selfName;
}

float Town::getXCoord() {
	return selfXCoord;
}

float Town::getYCoord() {
	return selfYCoord;
}

int Town::getDistance(float currentX, float currentY) {
	int deltaY = (currentY - selfYCoord) * 10;
	if (deltaY < 0) {
		deltaY *= -1;
	}

	int deltaX = (currentX - selfXCoord) * 10;
	if (deltaX < 0) {
		deltaX *= -1;
	}

	return (deltaX + deltaY);
}

Item::EconomyTypes Town::getRequired() {
	return selfRequires;
}

Item::EconomyTypes Town::getProduced() {
	return selfProduces;
}
