#include "player.h"

Player::Player(string initName) {
	name = initName;
	gold = 0;
}

void Player::checkInventory() {
	if (items.size() == 0) {
		printString("Your inventory is empty\n");
	}
	else {
		for (int i = 0; i < items.size(); i++) {
			printString(to_string(i + 1) + ": " + items[i].getItemName() + " -- " + to_string(items[i].getItemQuantity()) + "\n");
		}
	}
}

void Player::collectItem(Item newItem) {
	items.emplace_back(newItem);
}

void Player::dropItem(int itemIndex) {
	items.erase(items.begin() + itemIndex);
}
