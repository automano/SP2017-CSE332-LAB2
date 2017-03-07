// Name and Student ID
Zhening Li 445612

// Lab Number
Lab 2

// Purpose
          (1) repeatedly display the current state of a single-player game
          (2) prompt the user and receive input for the next move in the game
          (3) check whether or not each input move is valid, and if it is update the game state
          (4) detect the following three conditions: successful completion of the game, if the game has reached a point where no further valid moves are possible, or if there are still remaining valid moves available.

// Error 
// #1
Code:  game_piece[y*GAMEBOARD_HORIZONTAL_SIZE + x] = " ";

Decription:
     Severity	Code	Description	Project	File	Line	Suppression State
Error (active)		no operator "=" matches these operands	lab2	d:\Project\CSE504\lab2\lab2\ninealmonds.cpp	29	

Solution: game_piece[y*GAMEBOARD_HORIZONTAL_SIZE + x].push_back(" ");

//

