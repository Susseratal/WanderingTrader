#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <thread>

#include "engine.cpp"
#include "player.h"
#include "item.h"

using namespace std;
using namespace Engine;

int main() {
    printString("Choose a name for your character: ");
    string playerName;
    cin >> playerName;
    playerName = toTitle(playerName);
    Player player(playerName);

    printString("Welcome, " + playerName + "\n");

    Rock rock(3);
    player.collectItem(rock);

    string action;
    while (true) {
        printString("What would you like to do: ");
        cin >> action;
        action = toLower(action);

        switch (s_actionMappings[action]) {
        case av_travel: {
            printString("Behold, my locations: \n");
            // list all destinations
            break;
        }

        case av_inventory: {
            player.checkInventory();
            break;
        }

        case av_quit: {
            string certain;
            printString("Are you sure you want to quit? (y/n) ");
            cin >> certain;
            certain = toLower(certain);
            if (certain == "y") {
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
