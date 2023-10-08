#pragma once

#include <string>
#include <vector>
#include <map>

#include "town.h"

using namespace std;

namespace Engine {
	extern vector<Town> towns;

	enum Action {
		av_undefined,
		av_travel,
		av_barter,
		av_inventory,
		av_quit
	};

	extern map<char, Action> s_actionMappings;

	void printString(string text);
	string toTitle(string s);
	string toLower(string s);
	string spacer(int blockSize, int stringLen, char c);
	int digitCount(int n);
}
