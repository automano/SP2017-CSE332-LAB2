// ninealmonds.cpp
// Author: Zhening Li E-mail: zhening.li@wustl.edu
// Purpose: 
//          Declare and define a class that implements a single-player game version of the the Nine Almonds puzzle

#include "stdafx.h"
#include "ninealmonds.h"

#include "common.h"

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
	os << " 0 1 2 3 4 " << endl; // print horizontal index
	return os;
}

// Constructor
NineAlmonds::NineAlmonds() { // Initialize the game board
	game_piece.resize(GAMEBOARD_HORIZONTAL_SIZE*GAMEBOARD_VERTICAL_SIZE);
	//for (unsigned int y = 0; y < GAMEBOARD_VERTICAL_SIZE;y++)
	//{
	//	for (unsigned int x = 0;x < GAMEBOARD_HORIZONTAL_SIZE;x++)
	//	{
	//		if (x == 0 || x == GAMEBOARD_HORIZONTAL_SIZE - 1 || y == 0 || y == GAMEBOARD_VERTICAL_SIZE - 1)
	//			// the inner nine squares of the board should all have brown almonds on them
	//			game_piece[y*GAMEBOARD_HORIZONTAL_SIZE + x] = " ";
	//		else
	//			// the outer sixteen squares of the board should be empty.
	//			game_piece[y*GAMEBOARD_HORIZONTAL_SIZE + x] = "A";
	//	}
	//}
	game_piece[4 * GAMEBOARD_HORIZONTAL_SIZE + 0] = " ";game_piece[4 * GAMEBOARD_HORIZONTAL_SIZE + 1] = " ";game_piece[4 * GAMEBOARD_HORIZONTAL_SIZE + 2] = " ";game_piece[4 * GAMEBOARD_HORIZONTAL_SIZE + 3] = " ";game_piece[4 * GAMEBOARD_HORIZONTAL_SIZE + 4] = " ";
	game_piece[3 * GAMEBOARD_HORIZONTAL_SIZE + 0] = "A";game_piece[3 * GAMEBOARD_HORIZONTAL_SIZE + 1] = " ";game_piece[3 * GAMEBOARD_HORIZONTAL_SIZE + 2] = " ";game_piece[3 * GAMEBOARD_HORIZONTAL_SIZE + 3] = " ";game_piece[3 * GAMEBOARD_HORIZONTAL_SIZE + 4] = " ";
	game_piece[2 * GAMEBOARD_HORIZONTAL_SIZE + 0] = "A";game_piece[2 * GAMEBOARD_HORIZONTAL_SIZE + 1] = " ";game_piece[2 * GAMEBOARD_HORIZONTAL_SIZE + 2] = "A";game_piece[2 * GAMEBOARD_HORIZONTAL_SIZE + 3] = " ";game_piece[2 * GAMEBOARD_HORIZONTAL_SIZE + 4] = " ";
	game_piece[1 * GAMEBOARD_HORIZONTAL_SIZE + 0] = " ";game_piece[1 * GAMEBOARD_HORIZONTAL_SIZE + 1] = " ";game_piece[1 * GAMEBOARD_HORIZONTAL_SIZE + 2] = " ";game_piece[1 * GAMEBOARD_HORIZONTAL_SIZE + 3] = " ";game_piece[1 * GAMEBOARD_HORIZONTAL_SIZE + 4] = " ";
	game_piece[0 * GAMEBOARD_HORIZONTAL_SIZE + 0] = "A";game_piece[0 * GAMEBOARD_HORIZONTAL_SIZE + 1] = " ";game_piece[0 * GAMEBOARD_HORIZONTAL_SIZE + 2] = " ";game_piece[0 * GAMEBOARD_HORIZONTAL_SIZE + 3] = " ";game_piece[0 * GAMEBOARD_HORIZONTAL_SIZE + 4] = " ";
	turn_s = 0;
}

// Method: done()
bool NineAlmonds::done() {
	unsigned int empty_count = 0; // Counter of empty pieces
	const int CENTER_INDEX = 12; // index of coordinate 2,2
	const int EMPTY_COUNT = 24;  // Should have 24 empty pieces 
	for (unsigned int y = 0; y < GAMEBOARD_VERTICAL_SIZE;y++)
	{
		for (unsigned int x = 0;x < GAMEBOARD_HORIZONTAL_SIZE;x++)
		{
			if (game_piece[y*GAMEBOARD_HORIZONTAL_SIZE + x] == " ")
			{
				empty_count++; // count empty game pieces number
			}
		}
	}
	if (empty_count == EMPTY_COUNT&&game_piece[CENTER_INDEX] == "A")
		// exactly one almond positioned at the center of the board (the square with coordinate 2,2), and all other squares are empty
		return true;
	else
		return false;
}

//Method: stalemate()
bool NineAlmonds::stalemate() {
	if (done()) //if the done() method returns true
		return false;
	else
	{// traverse the game board to check valid moves
	 // Brute Force
		for (int y = 0; y < GAMEBOARD_VERTICAL_SIZE;y++)
		{
			for (int x = 0;x < GAMEBOARD_HORIZONTAL_SIZE;x++)
			{
				// neighbor index
				int x_left_n = x - 1;
				int x_right_n = x + 1;
				int y_down_n = y - 1;
				int y_up_n = y + 1;
				// destination index
				int x_left_d = x - 2;
				int x_right_d = x + 2;
				int y_down_d = y - 2;
				int y_up_d = y + 2;

				// find a almonds first
				if (game_piece[y*GAMEBOARD_HORIZONTAL_SIZE + x] == "A")
				{ // check #1 move (left down)
					if (x_left_n >= 0 && x_left_n < GAMEBOARD_HORIZONTAL_SIZE &&
						y_down_n >= 0 && y_down_n < GAMEBOARD_VERTICAL_SIZE && // check if neighbor on the game board
						game_piece[y_down_n*GAMEBOARD_HORIZONTAL_SIZE + x_left_n] == "A" && //check there is an almond on the square that is in between the two squares
						x_left_d >= 0 && x_left_d < GAMEBOARD_HORIZONTAL_SIZE &&
						y_down_d >= 0 && y_down_d < GAMEBOARD_VERTICAL_SIZE && // check if destination on the game board
						game_piece[y_down_d*GAMEBOARD_HORIZONTAL_SIZE + x_left_d] == " ") // ends with an empty square that is two positions away
						return false;

					//check #2 move (down)
					else if (
						x >= 0 && x < GAMEBOARD_HORIZONTAL_SIZE &&
						y_down_n >= 0 && y_down_n < GAMEBOARD_VERTICAL_SIZE &&// check if neighbor on the game board
						game_piece[y_down_n*GAMEBOARD_HORIZONTAL_SIZE + x] == "A" && //check there is an almond on the square that is in between the two squares
						x >= 0 && x < GAMEBOARD_HORIZONTAL_SIZE &&
						y_down_d >= 0 && y_down_d < GAMEBOARD_VERTICAL_SIZE && // check if destination on the game board
						game_piece[y_down_d*GAMEBOARD_HORIZONTAL_SIZE + x] == " ") // ends with an empty square that is two positions away
						return false;

					// check #3 move (right down)
					else if (
						x_right_n >= 0 && x_right_n < GAMEBOARD_HORIZONTAL_SIZE &&
						y_down_n >= 0 && y_down_n < GAMEBOARD_VERTICAL_SIZE &&// check if neighbor on the game board
						game_piece[y_down_n*GAMEBOARD_HORIZONTAL_SIZE + x_right_n] == "A" && //check there is an almond on the square that is in between the two squares
						x_right_d >= 0 && x_right_d < GAMEBOARD_HORIZONTAL_SIZE &&
						y_down_d >= 0 && y_down_d < GAMEBOARD_VERTICAL_SIZE && // check if destination on the game board
						game_piece[y_down_d*GAMEBOARD_HORIZONTAL_SIZE + x_right_d] == " ") // ends with an empty square that is two positions away
						return false;

					// check #4 move (left)
					else if (
						x_left_n >= 0 && x_left_n < GAMEBOARD_HORIZONTAL_SIZE &&
						y_up_n >= 0 && y_up_n < GAMEBOARD_VERTICAL_SIZE &&// check if neighbor on the game board
						game_piece[y_up_n*GAMEBOARD_HORIZONTAL_SIZE + x_left_n] == "A" && //check there is an almond on the square that is in between the two squares
						x_left_d >= 0 && x_left_d < GAMEBOARD_HORIZONTAL_SIZE &&
						y >= 0 && y < GAMEBOARD_VERTICAL_SIZE && // check if destination on the game board
						game_piece[y*GAMEBOARD_HORIZONTAL_SIZE + x_left_d] == " ") // ends with an empty square that is two positions away
						return false;

					// check #5 move (right)
					else if (
						x_right_n >= 0 && x_right_n < GAMEBOARD_HORIZONTAL_SIZE &&
						y >= 0 && y < GAMEBOARD_VERTICAL_SIZE &&// check if neighbor on the game board
						game_piece[y*GAMEBOARD_HORIZONTAL_SIZE + x_right_n] == "A" && //check there is an almond on the square that is in between the two squares
						x_right_d >= 0 && x_right_d < GAMEBOARD_HORIZONTAL_SIZE &&
						y >= 0 && y < GAMEBOARD_VERTICAL_SIZE && // check if destination on the game board
						game_piece[y*GAMEBOARD_HORIZONTAL_SIZE + x_right_d] == " ") // ends with an empty square that is two positions away
						return false;

					// check #6 move (left up)
					else if (
						x_left_n >= 0 && x_left_n < GAMEBOARD_HORIZONTAL_SIZE &&
						y_up_n >= 0 && y_up_n < GAMEBOARD_VERTICAL_SIZE &&// check if neighbor on the game board
						game_piece[y_up_n*GAMEBOARD_HORIZONTAL_SIZE + x_left_n] == "A" && //check there is an almond on the square that is in between the two squares
						x_left_d >= 0 && x_left_d < GAMEBOARD_HORIZONTAL_SIZE &&
						y_up_d >= 0 && y_up_d < GAMEBOARD_VERTICAL_SIZE && // check if destination on the game board
						game_piece[y_up_d*GAMEBOARD_HORIZONTAL_SIZE + x_left_d] == " ") // ends with an empty square that is two positions away
						return false;

					// check #7 move (up)
					else if (
						x >= 0 && x < GAMEBOARD_HORIZONTAL_SIZE &&
						y_up_n >= 0 && y_up_n < GAMEBOARD_VERTICAL_SIZE &&// check if neighbor on the game board
						game_piece[y_up_n*GAMEBOARD_HORIZONTAL_SIZE + x] == "A" && //check there is an almond on the square that is in between the two squares
						x >= 0 && x < GAMEBOARD_HORIZONTAL_SIZE &&
						y_up_d >= 0 && y_up_d < GAMEBOARD_VERTICAL_SIZE && // check if destination on the game board
						game_piece[y_up_d*GAMEBOARD_HORIZONTAL_SIZE + x] == " ") // ends with an empty square that is two positions away
						return false;

					// check #8 move (right up)
					else if (
						x_right_n >= 0 && x_right_n < GAMEBOARD_HORIZONTAL_SIZE &&
						y_up_n >= 0 && y_up_n < GAMEBOARD_VERTICAL_SIZE &&// check if neighbor on the game board
						game_piece[y_up_n*GAMEBOARD_HORIZONTAL_SIZE + x_right_n] == "A" && //check there is an almond on the square that is in between the two squares
						x_right_d >= 0 && x_right_d < GAMEBOARD_HORIZONTAL_SIZE &&
						y_up_d >= 0 && y_up_d < GAMEBOARD_VERTICAL_SIZE && // check if destination on the game board
						game_piece[y_up_d*GAMEBOARD_HORIZONTAL_SIZE + x_right_d] == " ") // ends with an empty square that is two positions away
						return false;
				}
			}
		}
		return true;
	}
}

// Method: prompt()
int NineAlmonds::prompt(unsigned int &x, unsigned int &y) {
	bool comma_flag = false;

	cout << "Enter coordinates <x,y> or type <quit> to end." << endl;
	string coordinates;
	cin >> coordinates;
	LowerCase(coordinates);
	if (!coordinates.compare("quit")) {
		return PLAYER_QUIT;
	}

	for (unsigned int i = 0;i <= coordinates.size();i++) 
	{
		if (coordinates[i] == ',') 
		{
			coordinates[i] = ' ';
			comma_flag = true;
		}
	}

	stringstream ss;
	ss << coordinates;

	if (comma_flag)
	{
		if (!(ss >> x >> y))
		{
			cout << "Invalid format input! Please enter <X,Y>!" << endl;
			return FAIL_EXTRACT_COORDINATES;
		}
		else if (x < 1 || x>3 || y < 1 || y>3)  //check the input move is on the inner nine squares of the board
		{
			cout << "Input coordinates are out of game board range! Please enter coordinates between <0,0> and <4,4>!" << endl;
			return INPUT_OUT_OF_RANGE;
		}
		else
		{
			return SUCCESS;
		}
	}
	else
	{
		cout << "Invalid format input! Please enter <X,Y>!" << endl;
		return NO_COMMA;
	}
}

//Method: turn()
int NineAlmonds::turn() {

	
	// beginning square coordinates
	unsigned int x_o;
	unsigned int y_o;
	// ending square coordinates
	unsigned int x_d;
	unsigned int y_d;

	cout << "Enter beginning square coordinates!" << endl;
	if (prompt(x_o, y_o) == PLAYER_QUIT)
	{
		return QUIT_GAME;
	}
	cout << "Enter ending square coordinates!" << endl;
	if (prompt(x_d, y_d) == PLAYER_QUIT)
	{
		return QUIT_GAME;
	}


	return SUCCESS;
}