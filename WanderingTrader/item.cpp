#include "item.h"

Item::Item(string itemName, int itemVal, int itemQuantity, float itemWeight) :
	selfName(itemName),
	selfVal(itemVal),
	selfQuantity(itemQuantity),
	selfWeight(itemWeight) {}

string Item::getItemName() {
	return selfName;
}

int Item::getItemVal() { 
	return selfVal;
}

int Item::getItemQuantity() {
	return selfQuantity;
}

float Item::getItemWeight() {
	return selfWeight;
}

Stone::Stone(int itemQuantity) : Item("Stone", 5, itemQuantity, 5) {}
Wood::Wood(int itemQuantity) : Item("Wood", 2, itemQuantity, 3) {}
Iron::Iron(int itemQuantity) : Item("Iron Ore", 8, itemQuantity, 7) {}
Bread::Bread(int itemQuantity) : Item("Bread", 6, itemQuantity, 1) {}
Fish::Fish(int itemQuantity) : Item("Fish", 2, itemQuantity, 0.5) {}
Carrot::Carrot(int itemQuantity) : Item("Carrot", 1, itemQuantity, 0.2) {}