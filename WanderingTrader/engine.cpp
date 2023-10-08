#define _CRT_SECURE_NO_WARNINGS

#include <thread>
#include <chrono>
#include <iostream>

#include "engine.h"


using namespace std;

namespace Engine {
	vector<Town> towns = {
		Town("Dustwich", 0.2, 0.1),
		Town("Dragongulch", 0.4, 0.2),
		Town("Smallpond", 0.2, 0.3),
		Town("Highmount", 0.2, 0.8),
		Town("Newpost", 0.5, 0.6),
		Town("Amberfield", 0.5, 0.9),
		Town("Baymeadow", 0.8, 0.5),
		Town("Hearthollow", 0.8, 0.3),
		Town("Eastburgh", 1.0, 0.7)
	};

	map<char, Action> s_actionMappings = {
		{'t', av_travel},
		{'b', av_barter},
		{'i', av_inventory},
		{'q', av_quit}
	};

	void printString(string text) {
		int textLen = text.length();
		char* textArray = new char[textLen + 1]; // in order to use a variable to init an array, a "dynamically sized array" is better
		strcpy(textArray, text.c_str());
		for (int i = 0; i < textLen; i++) {
			cout << textArray[i] << flush;
			this_thread::sleep_for(chrono::milliseconds(5));
		}
	}

	string toTitle(string s) {
		int inputLen = s.length();
		char* inputArray = new char[inputLen + 1];
		strcpy(inputArray, s.c_str());
		for (int i = 0; i < inputLen; i++) {
			if (i == 0) {
				inputArray[i] = toupper(inputArray[i]);
			}
			else {
				inputArray[i] = tolower(inputArray[i]);
			}
		}
		string returnStr(inputArray);
		return returnStr;
	}

	string toLower(string s) {
		int inputLen = s.length();
		char* inputArray = new char[inputLen + 1];
		strcpy(inputArray, s.c_str());
		for (int i = 0; i < inputLen; i++) {
			inputArray[i] = tolower(inputArray[i]);
		}
		string returnStr(inputArray);
		return returnStr;
	}

	string spacer(int blockSize, int stringLen, char c) {
		string spacer((blockSize - stringLen), c);
		return(spacer);
	}

	int digitCount(int n) {
		return int(log10(n) + 1);
	}
}

