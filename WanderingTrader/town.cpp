#include "town.h"

Town::Town(string name, float xCoord, float yCoord) :
	selfName(name),
	selfXCoord(xCoord),
	selfYCoord(yCoord) {
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
