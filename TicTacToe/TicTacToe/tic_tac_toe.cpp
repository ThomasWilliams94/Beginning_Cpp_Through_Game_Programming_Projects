// Tic-Tac-Toe
// Plays the game of tic-tac-toe against a human opponent

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// global constant
const char X = 'X';
const char O = 'O';
const char EMPTY = ' ';
const char TIE = 'T';
const char NO_ONE = 'N';

// function prototypes

//Displays the game instructions
void instructions();

// Asks a yes or no question. 
// Receives a question.
// Returns either a 'y' or an 'n'.
char askYesNo(string question);

// Asks for a number within a range.
// Receives a question, a low numbear, and a high number.
// Returns a number in the range from low to high. 
int askNumber(string question, int high, int low = 0);

// Determines the human's piece. 
// Returns either an 'X' or an 'O'.
char humanPiece();

// Calculates the opposing piece given a piece. 
// Receives either an 'X' or an 'O'. 
// Returns either an 'X' or an 'O'.
char opponent(char piece);

// Displays the board on the screen.
// Receives a board.
void displayBoard(const vector<char>& board);

// Determines the game winner. 
// Receives a board.
// Returns an 'X', an 'O', a 'T' (to indicate a tie), 
// or 'N' (to indicate that no one has won yet.
char winner(const vector<char>& board);

// Determines whether a move is legal.
// Receives a board and a move. 
// Returns either true or false;
bool isLegal(const vector<char>& board, char human);

// Gets the human's move. 
// Receives a game board and the human's piece.
// Return's the human's move. 
int humanMove(const vector<char>& board, char human);

// Gets the computer's move. 
// Receives a game board and the computer's piece.
// Return's the computer's move. 
int computerMove(vector<char> board, char computer);

// Congratulates the winner or declares a tie.
// Receives the winning side, the computer's piece, and the human's piece. 
void announceWinner(char winner, char computer, char human);

