#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

class Item {
public: 
	enum EconomyTypes {
		Agriculture,
		Mining,
		Refinery,
		Fishing,
		Farming,
	};

	string getItemName();
	int getItemVal();
	int getItemQuantity();
	float getItemWeight();

protected: 
	Item(string itemName, int itemVal, int itemQuantity, float itemWeight, EconomyTypes itemType);

	string selfName;
	int selfVal;
	int selfQuantity;
	float selfWeight;
	EconomyTypes selfType;
};

/* /////////////////// */

class Stone : public Item {
public: 
	Stone(int itemQuantity);
};

class Wood : public Item {
public:
	Wood(int itemQuantity);
};

class Iron : public Item {
public:
	Iron(int itemQuantity);
};

class Bread : public Item {
public:
	Bread(int itemQuantity);
};

class Fish : public Item {
public:
	Fish(int itemQuantity);
};

class Carrot : public Item {
public:
	Carrot(int itemQuantity);
};
