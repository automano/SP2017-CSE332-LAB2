// lab2.cpp
// Author: Zhening Li E-mail: zhening.li@wustl.edu
// Purpose: develop a C++ program with a game class that can 
//          (1) repeatedly display the current state of a single-player game
//          (2) prompt the user and receive input for the next move in the game
//          (3) check whether or not each input move is valid, and if it is update the game state
//          (4) detect the following three conditions: successful completion of the game, if the game has reached a point where no further valid moves are possible, or if there are still remaining valid moves available.

#include "stdafx.h"
#include "common.h"
#include "ninealmonds.h"

int main(int argc, char *argv[])
{
	if (argc == CDM_ARGUMENTS_NUMBER&&strcmp(argv[GAME_NAME], "NineAlmonds") == 0)
	{
		NineAlmonds newgame;
		cout << endl << "Begin Game NineAlmonds!" << endl << endl;
		return newgame.play();
	}
	else
	{
		char * program_name = argv[PROGRAM_NAME];
		char * second_argument = "NineAlmonds";
		return UsageMessage(program_name, second_argument);// call usage message 
	}
}

