#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>

#include "item.h"
#include "engine.cpp"

using namespace std;
using namespace Engine;

class Player
{
public: 
	string name;
	float gold;

	Player(string initName);
	void checkInventory();
	void collectItem(Item newItem);
	void dropItem(int itemIndex);

private: 
	vector<Item> items;
};

