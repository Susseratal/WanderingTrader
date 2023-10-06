#include "item.h"

Item::Item(int itemQuantity) {
	selfQuantity = itemQuantity;
}

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

Rock::Rock(int selfQuantity) : Item(selfQuantity) {
	selfName = "Rock";
	selfType = itemTypes::junk;
	selfVal = 0.2;
}
