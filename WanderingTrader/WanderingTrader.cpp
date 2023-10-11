#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <thread>
#include <conio.h>

#include "engine.h"
#include "player.h"
#include "item.h"

using namespace std;
using namespace Engine;

int main() {
    clearScreen();
    printString("Choose a name for your character: ");
    string playerName;
    cin >> playerName;
    playerName = toTitle(playerName);

    Player player(playerName, &towns[0]);
    printString("\"Good Morning, " + playerName + "!\" Says the innkeeper\n");
    printString("You have awoken in the town of " + player.currentTown->getName() + ".\n\n");

    string action;
    while (true) {
        printString("What would you like to do: ");
        char action = _getch();
        cout << action << "\n";

        switch (s_actionMappings[action]) {
        case av_travel: {
            int tableWidth = 23;
            printString("You are currently in " + player.currentTown->getName() + ".\n\n");
            printString("Travel to: \n");
			printString("|" + spacer(tableWidth, 0, '-') + "|\n");
            for (int i = 0; i < towns.size(); i++) {
                if (towns[i].getName() != player.currentTown->getName()) {
                    int currentTravel = towns[i].getDistance(player.currentTown->getXCoord(), player.currentTown->getYCoord());
					printString("| " + towns[i].getName() + spacer(15, towns[i].getName().length(), ' ') + "|  " + to_string(currentTravel) + spacer(4, digitCount(currentTravel), ' ') + "|\n");
                }
            }
			printString("|" + spacer(tableWidth, 0, '-') + "|\n");

            string targetPlace;
            printString("Please choose a location: ");
            cin >> targetPlace;
            targetPlace = toTitle(targetPlace);

            bool validTarget = false;
            int targetIndex;

            int timeToWait = 0;
            for (int i = 0; i < towns.size(); i++) {
                if (towns[i].getName() != player.currentTown->getName() && towns[i].getName() == targetPlace) {
                    timeToWait = towns[i].getDistance(player.currentTown->getXCoord(), player.currentTown->getYCoord());
                    validTarget = true;
                    targetIndex = i;
                    break;
                }
                else if (towns[i].getName() == targetPlace) {
                    printString("You are already at " + targetPlace + ".\n");
                    validTarget = true;
                    break;
                }
            }

            if(validTarget == false) {
                printString("No such place as " + targetPlace + ".\n");
            }

            if (timeToWait != 0) {
                for (int i = 0; i < timeToWait; i++) {
                    this_thread::sleep_for(chrono::seconds(1));
                    cout << ".";
                }
                cout << "\n";
                // every turn it should do something for feedback
				// this_thread::sleep_for(chrono::seconds(timeToWait));
                player.currentTown = &towns[targetIndex];
				printString("You have arrived in " + player.currentTown->getName() + ".\n\n");
            }
            break;
        }

        case av_barter: {
            break;
        }

        case av_inventory: {
            player.checkInventory();
            break;
        }

        case av_quit: {
            printString("Are you sure you want to quit? (y/n) ");
            char certain = _getch();
			cout << certain << "\n";
            if (certain == 'y') {
                return 0;
            }
            else {
                break;
            }
        }

        default: {
            printString("Unrecognised Command\n");
            break;
        }
        }
    }

    return 0;
}
