#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

class Item {
public: 
	enum itemTypes {
		clothes,
		weapon,
		food,
		material,
		junk
	};

	Item(int itemQuantity);
	string getItemName();
	itemTypes getItemType();
	float getItemVal();
	int getItemQuantity();

protected: 
	string selfName = "Item";
	itemTypes selfType = itemTypes::junk;
	float selfVal = 0;
	int selfQuantity = 0;
};

/* /////////////////// */

class Rock : public Item {
public: 
	Rock(int itemQuantity);
};
