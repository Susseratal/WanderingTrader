#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <vector>

#include "item.h"
#include "town.h"

using namespace std;
using namespace Engine;

class Player
{
public: 
	string name;
	Town* currentTown;

	Player(string initName, Town* startingTown);
	void checkInventory();
	bool collectItem(Item newItem);
	void dropItem(int itemIndex);

	void addCoin(int newGold, int newSilver, int newCopper);

	int getGold();
	int getSilver();
	int getCopper();

private: 
	vector<Item> items;

	int gold;
	int silver;
	int copper;
	float maxWeight;
	float currentWeight;
};

