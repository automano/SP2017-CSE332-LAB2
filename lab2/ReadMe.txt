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
 Program crash!
 Because I use an unsigned int variable to calculate the distance between beginning square and ending square, but distance sometimes is negative number. 

 	unsigned int x_m = x_o + (x_d - x_o) / 2;
	unsigned int y_m = y_o + (y_d - y_o) / 2;

 Solution:

 	unsigned int x_m = x_o + int((x_d - x_o)) / 2;
	unsigned int y_m = y_o + int((y_d - y_o)) / 2;



// Test
// #1 bad formed command line

D:\Project\CSE504\lab2\Debug>lab2.exe
Usage: lab2.exe NineAlmonds

D:\Project\CSE504\lab2\Debug>lab2.exe asdasjkdha
Usage: lab2.exe NineAlmonds

D:\Project\CSE504\lab2\Debug>lab2.exe NineAlmonds asdasd
Usage: lab2.exe NineAlmonds

// #2 bad formed input <x,y> for beginning and ending squares

D:\Project\CSE504\lab2\Debug>lab2.exe NineAlmonds

Begin Game NineAlmonds!

4
3  A A A
2  A A A
1  A A A
0
 0 1 2 3 4

New turn!The #0 turn!
Enter beginning square coordinates!
Enter coordinates <x,y> or type <quit> to quit this game.
2
Invalid format input! Please enter <X,Y>!
Enter beginning square coordinates!
Enter coordinates <x,y> or type <quit> to quit this game.
2,2
Enter ending square coordinates!
Enter coordinates <x,y> or type <quit> to quit this game.
2
Invalid format input! Please enter <X,Y>!
Enter beginning square coordinates!
Enter coordinates <x,y> or type <quit> to quit this game.
2,2
Enter ending square coordinates!
Enter coordinates <x,y> or type <quit> to quit this game.
2,4
4    A
3  A   A
2  A   A
1  A A A
0
 0 1 2 3 4


2,2 to 2,4


Continue this turn (YyNn)?

// #3 bad formed input <x,y> for ending square in the the continue turn

4    A
3  A   A
2  A   A
1  A A A
0
 0 1 2 3 4


2,2 to 2,4


Continue this turn (YyNn)?
y
Enter coordinates <x,y> or type <quit> to quit this game.
2
Invalid format input! Please enter <X,Y>!
Enter coordinates <x,y> or type <quit> to quit this game.
2,
Invalid format input! Please enter <X,Y>!
Enter coordinates <x,y> or type <quit> to quit this game.
2,y
Invalid format input! Please enter <X,Y>!
Enter coordinates <x,y> or type <quit> to quit this game.
4,2
4
3  A
2  A   A A
1  A A A
0
 0 1 2 3 4


2,2 to 2,4 to 4,2


Continue this turn (YyNn)?

// #4 quit game 

D:\Project\CSE504\lab2\Debug>lab2.exe NineAlmonds

Begin Game NineAlmonds!

4
3  A A A
2  A A A
1  A A A
0
 0 1 2 3 4

New turn!The #0 turn!
Enter beginning square coordinates!
Enter coordinates <x,y> or type <quit> to quit this game.
quit
Player quit game!
Total turns: 1.

D:\Project\CSE504\lab2\Debug>lab2.exe NineAlmonds

Begin Game NineAlmonds!

4
3  A A A
2  A A A
1  A A A
0
 0 1 2 3 4

New turn!The #0 turn!
Enter beginning square coordinates!
Enter coordinates <x,y> or type <quit> to quit this game.
2,2
Enter ending square coordinates!
Enter coordinates <x,y> or type <quit> to quit this game.
quit
Player quit game!
Total turns: 1.

D:\Project\CSE504\lab2\Debug>lab2.exe NineAlmonds

Begin Game NineAlmonds!

4
3  A A A
2  A A A
1  A A A
0
 0 1 2 3 4

New turn!The #0 turn!
Enter beginning square coordinates!
Enter coordinates <x,y> or type <quit> to quit this game.
2,2
Enter ending square coordinates!
Enter coordinates <x,y> or type <quit> to quit this game.
2,4
4    A
3  A   A
2  A   A
1  A A A
0
 0 1 2 3 4


2,2 to 2,4


Continue this turn (YyNn)?
y
Enter coordinates <x,y> or type <quit> to quit this game.
quit
Player quit game!
Total turns: 1.



// #5 complete game  --- (follow the solution from http://www.pedagonet.com/mathgenius/answer229.html)
D:\Project\CSE504\lab2\Debug>lab2.exe NineAlmonds

Begin Game NineAlmonds!

4
3  A A A
2  A A A
1  A A A
0
 0 1 2 3 4

New turn!The #0 turn!
Enter beginning square coordinates!
Enter coordinates <x,y> or type <quit> to quit this game.
2,2
Enter coordinates <x,y> or type <quit> to quit this game.
2,0
4
3  A A A
2  A   A
1  A   A
0    A
 0 1 2 3 4


2,2 to 2,0


Continue this turn (YyNn)?
4,2
Invalid input, try y or n!
y
Enter coordinates <x,y> or type <quit> to quit this game.
4,2
4
3  A A A
2  A   A A
1  A
0
 0 1 2 3 4


2,2 to 2,0 to 4,2


Continue this turn (YyNn)?
y
Enter coordinates <x,y> or type <quit> to quit this game.
2,4
4    A
3  A A
2  A   A
1  A
0
 0 1 2 3 4


2,2 to 2,0 to 4,2 to 2,4


Continue this turn (YyNn)?
y
Enter coordinates <x,y> or type <quit> to quit this game.
0,2
4
3    A
2A A   A
1  A
0
 0 1 2 3 4


2,2 to 2,0 to 4,2 to 2,4 to 0,2


Continue this turn (YyNn)?
n
New turn!The #1 turn!
Enter beginning square coordinates!
Enter coordinates <x,y> or type <quit> to quit this game.
1,1
Enter coordinates <x,y> or type <quit> to quit this game.
1,3
4
3  A A
2A     A
1
0
 0 1 2 3 4


1,1 to 1,3


Continue this turn (YyNn)?
n
New turn!The #2 turn!
Enter beginning square coordinates!
Enter coordinates <x,y> or type <quit> to quit this game.
3,2
Enter coordinates <x,y> or type <quit> to quit this game.
1,4
4  A
3  A
2A
1
0
 0 1 2 3 4


3,2 to 1,4


Continue this turn (YyNn)?
y
Enter coordinates <x,y> or type <quit> to quit this game.
1,2
4
3
2A A
1
0
 0 1 2 3 4


3,2 to 1,4 to 1,2


Continue this turn (YyNn)?
n
New turn!The #3 turn!
Enter beginning square coordinates!
Enter coordinates <x,y> or type <quit> to quit this game.
0,2
Enter coordinates <x,y> or type <quit> to quit this game.
2,2
4
3
2    A
1
0
 0 1 2 3 4


0,2 to 2,2


Continue this turn (YyNn)?
n
Congratulations! You win!
Total turns: 4.


// #6  stalemate game 

D:\Project\CSE504\lab2\Debug>lab2.exe NineAlmonds

Begin Game NineAlmonds!

4
3  A A A
2  A A A
1  A A A
0
 0 1 2 3 4

New turn!The #0 turn!
Enter beginning square coordinates!
Enter coordinates <x,y> or type <quit> to quit this game.
2,2
Enter coordinates <x,y> or type <quit> to quit this game.
2,0
4
3  A A A
2  A   A
1  A   A
0    A
 0 1 2 3 4


2,2 to 2,0


Continue this turn (YyNn)?
y
Enter coordinates <x,y> or type <quit> to quit this game.
0,2
4
3  A A A
2A A   A
1      A
0
 0 1 2 3 4


2,2 to 2,0 to 0,2


Continue this turn (YyNn)?
y
Enter coordinates <x,y> or type <quit> to quit this game.
2,2
4
3  A A A
2    A A
1      A
0
 0 1 2 3 4


2,2 to 2,0 to 0,2 to 2,2


Continue this turn (YyNn)?
y
Enter coordinates <x,y> or type <quit> to quit this game.
2,4
4    A
3  A   A
2      A
1      A
0
 0 1 2 3 4


2,2 to 2,0 to 0,2 to 2,2 to 2,4


Continue this turn (YyNn)?
y
Enter coordinates <x,y> or type <quit> to quit this game.
0,2
4
3      A
2A     A
1      A
0
 0 1 2 3 4


2,2 to 2,0 to 0,2 to 2,2 to 2,4 to 0,2


Continue this turn (YyNn)?
y
Enter coordinates <x,y> or type <quit> to quit this game.
n
Invalid format input! Please enter <X,Y>!
Enter coordinates <x,y> or type <quit> to quit this game.
2,2
Invalid Move! Continue this turn(YyNn)?
n
New turn!The #1 turn!
Enter beginning square coordinates!
Enter coordinates <x,y> or type <quit> to quit this game.
3,2
Enter coordinates <x,y> or type <quit> to quit this game.
3,4
4      A
3
2A
1      A
0
 0 1 2 3 4


3,2 to 3,4


Continue this turn (YyNn)?
n
Sorry! No more valid moves!
Total turns: 2.
