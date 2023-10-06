#include "item.h"

Item::Item(string itemName, itemTypes itemType, float itemVal, int itemQuantity) :
	selfName(itemName),
	selfType(itemType),
	selfVal(itemVal),
	selfQuantity(itemQuantity) {}

string Item::getItemName() {
	return selfName;
}

Item::itemTypes Item::getItemType() {
	return selfType;
}

float Item::getItemVal() {
	return selfVal;
}

int Item::getItemQuantity() {
	return selfQuantity;
}

Rock::Rock(int itemQuantity) : Item("Rock", itemTypes::junk, 0.2, itemQuantity) {}
