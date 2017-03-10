// ninealmonds.h
// Author: Zhening Li E-mail: zhening.li@wustl.edu
// Purpose: 
//          Declare and define a class that implements a single-player game version of the the Nine Almonds puzzle
#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

const int GAMEBOARD_HORIZONTAL_SIZE = 5;
const int GAMEBOARD_VERTICAL_SIZE = 5;
const string ALMOND = "A";
const string EMPTY = " ";

class NineAlmonds {
	friend ostream & operator<<(ostream &os, const NineAlmonds &game_board);
private:
	vector<string> game_piece;
	unsigned int turn_s;
public:
	NineAlmonds();
	bool done();
	bool stalemate();
	int prompt(unsigned int &x, unsigned int &y);
	int turn();
	int play();
};

ostream & operator<<(ostream &os, const NineAlmonds &game_board);