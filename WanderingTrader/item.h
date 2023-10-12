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
		Livestock
	};

	map<string, EconomyTypes> s_EconomyNames;

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
/*       Mining        */
/* /////////////////// */

class Stone : public Item {
public: 
	Stone(int itemQuantity);
};

class RawIron : public Item {
public:
	RawIron(int itemQuantity);
};

/* /////////////////// */
/*       Refinery       */
/* /////////////////// */

class Iron : public Item {
public:
	Iron(int itemQuantity);
};

/* /////////////////// */
/*      Livestock      */
/* /////////////////// */

class Fish : public Item {
public:
	Fish(int itemQuantity);
};

/* /////////////////// */
/*      Agriculture      */
/* /////////////////// */

class Wood : public Item {
public:
	Wood(int itemQuantity);
};

class Bread : public Item {
public:
	Bread(int itemQuantity);
};

class Carrot : public Item {
public:
	Carrot(int itemQuantity);
};
