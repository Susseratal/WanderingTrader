#include "item.h"

Item::Item(string itemName, int itemVal, int itemQuantity, float itemWeight, EconomyTypes itemType) :
	selfName(itemName),
	selfVal(itemVal),
	selfQuantity(itemQuantity),
	selfWeight(itemWeight), 
	selfType(itemType) {}

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

Stone::Stone(int itemQuantity) : Item("Stone", 5, itemQuantity, 5, Mining) {}
RawIron::RawIron(int itemQuantity) : Item("Iron Ore", 7, itemQuantity, 7, Mining) {}
Iron::Iron(int itemQuantity) : Item("Iron Ingot", 10, itemQuantity, 7, Refinery) {}
Fish::Fish(int itemQuantity) : Item("Fish", 2, itemQuantity, 0.5, Livestock) {}
Wood::Wood(int itemQuantity) : Item("Wood", 2, itemQuantity, 3, Agriculture) {}
Bread::Bread(int itemQuantity) : Item("Bread", 6, itemQuantity, 1, Agriculture) {}
Carrot::Carrot(int itemQuantity) : Item("Carrot", 1, itemQuantity, 0.2, Agriculture) {}