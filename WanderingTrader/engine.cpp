#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <map>

using namespace std;

namespace Engine {
	static enum Action {
		av_undefined,
		av_travel,
		av_fight,
		av_trade,
		av_inventory,
		av_quit
	};

	static map<string, Action> s_actionMappings = {
		{"travel", av_travel},
		{"fight", av_fight},
		{"trade", av_trade},
		{"inv", av_inventory},
		{"quit", av_quit}
	};

	static void printString(string text) {
		int textLen = text.length();
		char* textArray = new char[textLen + 1]; // in order to use a variable to init an array, a "dynamically sized array" is better
		strcpy(textArray, text.c_str());
		for (int i = 0; i < textLen; i++) {
			cout << textArray[i] << flush;
			this_thread::sleep_for(chrono::milliseconds(5));
		}
	}

	static string toTitle(string s) {
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

	static string toLower(string s) {
		int inputLen = s.length();
		char* inputArray = new char[inputLen + 1];
		strcpy(inputArray, s.c_str());
		for (int i = 0; i < inputLen; i++) {
			inputArray[i] = tolower(inputArray[i]);
		}
		string returnStr(inputArray);
		return returnStr;
	}
}

