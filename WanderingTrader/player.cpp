#include <iostream>
#include "engine.h"
#include "player.h"

Player::Player(string initName, Town* startingTown) {
	name = initName;
	gold = 1;
	silver = 1;
	copper = 1;
	currentTown = startingTown;
	maxWeight = 50;
	currentWeight = 0;
}

void Player::checkInventory() {
	int tableWidth = 60;
	printString("|" + spacer(tableWidth, 0, '-') + "|\n");
	printString("|" + spacer(6, 0, ' ') + "Gold: " + to_string(gold) + spacer(6, digitCount(gold), ' ') + "|" + spacer(6, 0, ' ') + "Silver: " + to_string(silver) + spacer(6, digitCount(silver), ' ') + "|" + spacer(6, 0, ' ') + "Copper: " + to_string(copper) + spacer(6, digitCount(copper), ' ') + "|\n"); // 32
	printString("|" + spacer(tableWidth, 0, '-') + "|\n");
	printString("| 0" + spacer(3, 0, ' ') + "| Item Name" + spacer(6, 0, ' ') + "| Item Value" + spacer(5, 0, ' ') + "| Number Held" + spacer(8, 0, ' ') + "|\n");
	printString("|" + spacer(tableWidth, 0, '-') + "|\n");

	for (int i = 0; i < items.size(); i++) {
		printString("| " + to_string(i + 1) + spacer(4, digitCount(i + 1), ' ') + "| " + items[i].getItemName() + spacer(15, items[i].getItemName().length(), ' ') + "| " + to_string(items[i].getItemVal()) + spacer(15, digitCount(items[i].getItemVal()), ' ') + "| " + to_string(items[i].getItemQuantity()) + spacer(19, digitCount(items[i].getItemQuantity()), ' ') + "|\n");
	}

	printString("|" + spacer(tableWidth, 0, '-') + "|\n");
}

bool Player::collectItem(Item newItem) {
	float newWeight = (newItem.getItemWeight() * newItem.getItemQuantity());
	if (currentWeight + newWeight > maxWeight) {
		printString("You do not have enough bag space to carry that\n");
		return false;
	}
	else {
		items.emplace_back(newItem);
		currentWeight += newWeight;
		return true;
	}
}

void Player::dropItem(int itemIndex) {
	items.erase(items.begin() + itemIndex);
}

void Player::addCoin(int newGold, int newSilver, int newCopper) {
	gold += newGold;
	silver += newSilver;
	copper += newCopper;

	if (copper >= 10) {
		int newSilver = copper / 10;
		silver += newSilver;
		int newCopper = copper % 10;
		copper = newCopper;
	}

	if (silver >= 10) {
		int newGold = silver / 10;
		gold += newGold;
		int newSilver = silver % 10;
		silver = newSilver;
	}
}

int Player::getGold() {
	return gold;
}

int Player::getSilver() {
	return silver;
}

int Player::getCopper() {
	return copper;
}
