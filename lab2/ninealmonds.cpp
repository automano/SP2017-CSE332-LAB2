// ninealmonds.cpp
// Author: Zhening Li E-mail: zhening.li@wustl.edu
// Purpose: 
//          Declare and define a class that implements a single-player game version of the the Nine Almonds puzzle

#include "stdafx.h"
#include "ninealmonds.h"

ostream & operator<<(ostream &os, const NineAlmonds &game_board) { // print out the game board
	for (int y = GAMEBOARD_VERTICAL_SIZE - 1; y >= 0;--y)
	{
		os << y; // print vertical index
		for (unsigned int x = 0;x < GAMEBOARD_HORIZONTAL_SIZE;x++)
		{
			os << game_board.game_piece[y*GAMEBOARD_HORIZONTAL_SIZE + x] << " "; // print game poard
		}
		os << endl;
	}
	os << " 0 1 2 3 4" << endl; // print horizontal index
	return os;
}

NineAlmonds::NineAlmonds() { // Initialize the game board
	game_piece.resize(GAMEBOARD_HORIZONTAL_SIZE*GAMEBOARD_VERTICAL_SIZE);
	for (unsigned int y = 0; y < GAMEBOARD_VERTICAL_SIZE;y++)
	{
		for (unsigned int x = 0;x < GAMEBOARD_HORIZONTAL_SIZE;x++)
		{
			if (x == 0 || x == GAMEBOARD_HORIZONTAL_SIZE - 1 || y == 0 || y == GAMEBOARD_VERTICAL_SIZE - 1)
				// the inner nine squares of the board should all have brown almonds on them
				game_piece[y*GAMEBOARD_HORIZONTAL_SIZE + x] = " ";
			else
				// the outer sixteen squares of the board should be empty.
				game_piece[y*GAMEBOARD_HORIZONTAL_SIZE + x] = "A";
		}
	}
	turn = 0;
}
