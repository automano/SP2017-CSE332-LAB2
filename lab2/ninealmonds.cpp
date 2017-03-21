// ninealmonds.cpp
// Author: Zhening Li E-mail: zhening.li@wustl.edu
// Purpose: 
//          Declare and define a class that implements a single-player game version of the the Nine Almonds puzzle

#include "stdafx.h"
#include "ninealmonds.h"

#include "common.h"
#include <math.h>

const int DIS_MAX = 2;
const int DIS_MIN = 0;

ostream & operator<<(ostream &os, const NineAlmonds &game_board) { // print out the game board
	for (int y = GAMEBOARD_VERTICAL_SIZE - 1; y >= 0;--y)
	{
		os << y; // print vertical index
		for (unsigned int x = 0;x < GAMEBOARD_HORIZONTAL_SIZE;x++)
		{
			os << game_board.game_piece[y*GAMEBOARD_HORIZONTAL_SIZE + x] << EMPTY; // print game poard
		}
		os << endl;
	}
	os << " 0 1 2 3 4 " << endl; // print horizontal index
	return os;
}

// Constructor
NineAlmonds::NineAlmonds() { // Initialize the game board
	game_piece.resize(GAMEBOARD_HORIZONTAL_SIZE*GAMEBOARD_VERTICAL_SIZE);
	for (unsigned int y = 0; y < GAMEBOARD_VERTICAL_SIZE;y++)
	{
		for (unsigned int x = 0;x < GAMEBOARD_HORIZONTAL_SIZE;x++)
		{
			if (x == 0 || x == GAMEBOARD_HORIZONTAL_SIZE - 1 || y == 0 || y == GAMEBOARD_VERTICAL_SIZE - 1)
				// the inner nine squares of the board should all have brown almonds on them
				game_piece[y*GAMEBOARD_HORIZONTAL_SIZE + x] = EMPTY;
			else
				// the outer sixteen squares of the board should be empty.
				game_piece[y*GAMEBOARD_HORIZONTAL_SIZE + x] = ALMOND;
		}
	}
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
			if (game_piece[y*GAMEBOARD_HORIZONTAL_SIZE + x] == EMPTY)
			{
				empty_count++; // count empty game pieces number
			}
		}
	}
	if (empty_count == EMPTY_COUNT&&game_piece[CENTER_INDEX] == ALMOND)
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
				if (game_piece[y*GAMEBOARD_HORIZONTAL_SIZE + x] == ALMOND)
				{ // check #1 move (left down)
					if (x_left_n >= 0 && x_left_n < GAMEBOARD_HORIZONTAL_SIZE &&
						y_down_n >= 0 && y_down_n < GAMEBOARD_VERTICAL_SIZE && // check if neighbor on the game board
						game_piece[y_down_n*GAMEBOARD_HORIZONTAL_SIZE + x_left_n] == ALMOND && //check there is an almond on the square that is in between the two squares
						x_left_d >= 0 && x_left_d < GAMEBOARD_HORIZONTAL_SIZE &&
						y_down_d >= 0 && y_down_d < GAMEBOARD_VERTICAL_SIZE && // check if destination on the game board
						game_piece[y_down_d*GAMEBOARD_HORIZONTAL_SIZE + x_left_d] == EMPTY) // ends with an empty square that is two positions away
						return false;

					//check #2 move (down)
					else if (
						x >= 0 && x < GAMEBOARD_HORIZONTAL_SIZE &&
						y_down_n >= 0 && y_down_n < GAMEBOARD_VERTICAL_SIZE &&// check if neighbor on the game board
						game_piece[y_down_n*GAMEBOARD_HORIZONTAL_SIZE + x] == ALMOND && //check there is an almond on the square that is in between the two squares
						x >= 0 && x < GAMEBOARD_HORIZONTAL_SIZE &&
						y_down_d >= 0 && y_down_d < GAMEBOARD_VERTICAL_SIZE && // check if destination on the game board
						game_piece[y_down_d*GAMEBOARD_HORIZONTAL_SIZE + x] == EMPTY) // ends with an empty square that is two positions away
						return false;

					// check #3 move (right down)
					else if (
						x_right_n >= 0 && x_right_n < GAMEBOARD_HORIZONTAL_SIZE &&
						y_down_n >= 0 && y_down_n < GAMEBOARD_VERTICAL_SIZE &&// check if neighbor on the game board
						game_piece[y_down_n*GAMEBOARD_HORIZONTAL_SIZE + x_right_n] == ALMOND && //check there is an almond on the square that is in between the two squares
						x_right_d >= 0 && x_right_d < GAMEBOARD_HORIZONTAL_SIZE &&
						y_down_d >= 0 && y_down_d < GAMEBOARD_VERTICAL_SIZE && // check if destination on the game board
						game_piece[y_down_d*GAMEBOARD_HORIZONTAL_SIZE + x_right_d] == EMPTY) // ends with an empty square that is two positions away
						return false;

					// check #4 move (left)
					else if (
						x_left_n >= 0 && x_left_n < GAMEBOARD_HORIZONTAL_SIZE &&
						y_up_n >= 0 && y_up_n < GAMEBOARD_VERTICAL_SIZE &&// check if neighbor on the game board
						game_piece[y_up_n*GAMEBOARD_HORIZONTAL_SIZE + x_left_n] == ALMOND && //check there is an almond on the square that is in between the two squares
						x_left_d >= 0 && x_left_d < GAMEBOARD_HORIZONTAL_SIZE &&
						y >= 0 && y < GAMEBOARD_VERTICAL_SIZE && // check if destination on the game board
						game_piece[y*GAMEBOARD_HORIZONTAL_SIZE + x_left_d] == EMPTY) // ends with an empty square that is two positions away
						return false;

					// check #5 move (right)
					else if (
						x_right_n >= 0 && x_right_n < GAMEBOARD_HORIZONTAL_SIZE &&
						y >= 0 && y < GAMEBOARD_VERTICAL_SIZE &&// check if neighbor on the game board
						game_piece[y*GAMEBOARD_HORIZONTAL_SIZE + x_right_n] == ALMOND && //check there is an almond on the square that is in between the two squares
						x_right_d >= 0 && x_right_d < GAMEBOARD_HORIZONTAL_SIZE &&
						y >= 0 && y < GAMEBOARD_VERTICAL_SIZE && // check if destination on the game board
						game_piece[y*GAMEBOARD_HORIZONTAL_SIZE + x_right_d] == EMPTY) // ends with an empty square that is two positions away
						return false;

					// check #6 move (left up)
					else if (
						x_left_n >= 0 && x_left_n < GAMEBOARD_HORIZONTAL_SIZE &&
						y_up_n >= 0 && y_up_n < GAMEBOARD_VERTICAL_SIZE &&// check if neighbor on the game board
						game_piece[y_up_n*GAMEBOARD_HORIZONTAL_SIZE + x_left_n] == ALMOND && //check there is an almond on the square that is in between the two squares
						x_left_d >= 0 && x_left_d < GAMEBOARD_HORIZONTAL_SIZE &&
						y_up_d >= 0 && y_up_d < GAMEBOARD_VERTICAL_SIZE && // check if destination on the game board
						game_piece[y_up_d*GAMEBOARD_HORIZONTAL_SIZE + x_left_d] == EMPTY) // ends with an empty square that is two positions away
						return false;

					// check #7 move (up)
					else if (
						x >= 0 && x < GAMEBOARD_HORIZONTAL_SIZE &&
						y_up_n >= 0 && y_up_n < GAMEBOARD_VERTICAL_SIZE &&// check if neighbor on the game board
						game_piece[y_up_n*GAMEBOARD_HORIZONTAL_SIZE + x] == ALMOND && //check there is an almond on the square that is in between the two squares
						x >= 0 && x < GAMEBOARD_HORIZONTAL_SIZE &&
						y_up_d >= 0 && y_up_d < GAMEBOARD_VERTICAL_SIZE && // check if destination on the game board
						game_piece[y_up_d*GAMEBOARD_HORIZONTAL_SIZE + x] == EMPTY) // ends with an empty square that is two positions away
						return false;

					// check #8 move (right up)
					else if (
						x_right_n >= 0 && x_right_n < GAMEBOARD_HORIZONTAL_SIZE &&
						y_up_n >= 0 && y_up_n < GAMEBOARD_VERTICAL_SIZE &&// check if neighbor on the game board
						game_piece[y_up_n*GAMEBOARD_HORIZONTAL_SIZE + x_right_n] == ALMOND && //check there is an almond on the square that is in between the two squares
						x_right_d >= 0 && x_right_d < GAMEBOARD_HORIZONTAL_SIZE &&
						y_up_d >= 0 && y_up_d < GAMEBOARD_VERTICAL_SIZE && // check if destination on the game board
						game_piece[y_up_d*GAMEBOARD_HORIZONTAL_SIZE + x_right_d] == EMPTY) // ends with an empty square that is two positions away
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

	cout << "Enter coordinates <x,y> or type <quit> to quit this game." << endl;
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
		else if (x < 0 || x>4 || y < 0 || y>4)  //check the input move is on the inner nine squares of the board
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

	string turn_info = "";
	string in = "";

	// beginning square coordinates
	unsigned int x_o=0;
	unsigned int y_o=0;
	// ending square coordinates
	unsigned int x_d=0;
	unsigned int y_d=0;


	cout << "Enter beginning square coordinates!" << endl;
	int beginning_prompt_flag = this->prompt(x_o, y_o);
	if (beginning_prompt_flag == SUCCESS) {
		cout << "Enter ending square coordinates!" << endl;
		int ending_prompt_flag = this->prompt(x_d, y_d);
		if (ending_prompt_flag == SUCCESS) {
			// index of almond on the square that is in between the beginning ande ending squares
			unsigned int x_m = x_o + int((x_d - x_o)) / 2;
			unsigned int y_m = y_o + int((y_d - y_o)) / 2;
			if (validmove(x_o, y_o, x_d, y_d))
			{
				// set squares
				game_piece[y_o*GAMEBOARD_HORIZONTAL_SIZE + x_o] = EMPTY;
				game_piece[y_m*GAMEBOARD_HORIZONTAL_SIZE + x_m] = EMPTY;
				game_piece[y_d*GAMEBOARD_HORIZONTAL_SIZE + x_d] = ALMOND;
				// print current gaem board
				cout << *this << endl << endl;
				// print out move info
				turn_info = to_string(x_o) + "," + to_string(y_o) + " to " + to_string(x_d) + "," + to_string(y_d);
				cout << turn_info << endl << endl;
				// ask if user want to continue
				cout << endl << "Continue this turn (YyNn)?" << endl;
				cin >> in;
				LowerCase(in);
				while (in != "y" && in != "n") {
					cout << "Invalid input, try y or n!" << endl;
					cin >> in;
					LowerCase(in);
				}
				while (in == "y") {
					// beginning square coordinates
					x_o = x_d;
					y_o = y_d;
					// ending square coordinates
					int mid_promot_flag = this->prompt(x_d, y_d);
					if (mid_promot_flag == SUCCESS) {
						// index of almond on the square that is in between the beginning ande ending squares
						x_m = x_o + int((x_d - x_o)) / 2;
						y_m = y_o + int((y_d - y_o)) / 2;
						if (validmove(x_o, y_o, x_d, y_d)) {
							// set squares
							game_piece[y_o*GAMEBOARD_HORIZONTAL_SIZE + x_o] = EMPTY;
							game_piece[y_m*GAMEBOARD_HORIZONTAL_SIZE + x_m] = EMPTY;
							game_piece[y_d*GAMEBOARD_HORIZONTAL_SIZE + x_d] = ALMOND;
							// print current gaem board
							cout << *this << endl << endl;
							// print out move info
							turn_info = turn_info + " to " + to_string(x_d) + "," + to_string(y_d);
							cout << turn_info << endl << endl;
							// ask if user want to continue
							cout << endl << "Continue this turn (YyNn)?" << endl;
							cin >> in;
							LowerCase(in);
							while (in != "y" && in != "n") {
								cout << "Invalid input, try y or n!" << endl;
								cin >> in;
								LowerCase(in);
							}
						}
						else {
							cout << "Invalid Move! Continue this turn(YyNn)?" << endl;
							cin >> in;
							LowerCase(in);
							while (in != "y" && in != "n") {
								cout << "Invalid input, try y or n!" << endl;
								cin >> in;
								LowerCase(in);
							}
						}
					}
					else if(mid_promot_flag== PLAYER_QUIT){ // use quit game
						return QUIT_GAME;
						break;
					}
					else {// invalid input
						in = "y"; // continue this turn
					}

				}
				return SUCCESS;
			}
			else
			{
				cout << "Error: Invalid move!" << endl
					<< "A valid move:" << endl
					<< "(1) starts with a square on the board that contains an almond;" << endl
					<< "(2) ends with an empty square that is two positions away from the original square either diagonally, vertically, or horizontally;" << endl
					<< "(3) there is an almond on the square that is in between the two squares." << endl;
				turn();
				return INVALID_MOVE;
			}
		}
		else if (ending_prompt_flag == PLAYER_QUIT) { // use quit game
			return QUIT_GAME;
		}
		else {// invalid input
			turn(); // restart this turn
		}
	}
	else if (beginning_prompt_flag == PLAYER_QUIT) { // use quit game
		return QUIT_GAME;
	}
	else {// invalid input
		turn(); // restart this turn
	}
	return SUCCESS;
}

// Method: play()
int NineAlmonds::play() {
	cout << (*this) << endl;
	while (!done() && !stalemate()) {
		// indicate which turn 
		cout << "New turn!" << "The #" << turn_s << " turn!" << endl;
		turn_s = turn_s + 1;
		if (turn() == QUIT_GAME)
		{
			cout << "Player quit game!" << endl;
			cout << "Total turns: " << turn_s << "." << endl;
			return QUIT_GAME;
			break;
		}
	}
	if (done())
	{
		cout << "Congratulations! You win!" << endl;
		cout << "Total turns: " << turn_s << "." << endl;
		return SUCCESS;
	}

	if (stalemate())
	{
		cout << "Sorry! No more valid moves!" << endl;
		cout << "Total turns: " << turn_s << "." << endl;
		return STALEMATE;
	}
	return SUCCESS;
}

// check this move is valid or not
int NineAlmonds::validmove(unsigned int x_o, unsigned int y_o, unsigned int x_d, unsigned int y_d) {
	// index of almond on the square that is in between the beginning ande ending squares
	unsigned int x_m = x_o + int((x_d - x_o)) / 2;
	unsigned int y_m = y_o + int((y_d - y_o)) / 2;
	// distance between beginning square and ending square
	unsigned int x_dis = abs(int(x_d - x_o));
	unsigned int y_dis = abs(int(y_d - y_o));

	if ((x_dis == DIS_MAX || x_dis == DIS_MIN) && (y_dis == DIS_MAX || y_dis == DIS_MIN)
		&& game_piece[y_o*GAMEBOARD_HORIZONTAL_SIZE + x_o] == ALMOND
		&& game_piece[y_d*GAMEBOARD_HORIZONTAL_SIZE + x_d] == EMPTY
		&& game_piece[y_m*GAMEBOARD_HORIZONTAL_SIZE + x_m] == ALMOND)
		return true;
	else
		return false;
}