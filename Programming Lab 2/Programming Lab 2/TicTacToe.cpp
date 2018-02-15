#include <iostream>
#include <vector>
#include <string>

#include "TicTacToe.h"

using namespace std;

TicTacToe::TicTacToe()
	: question("\nPlayer one would you like to be the first to begin (Y/N): ")
	, empty(' ')
	, draw('D')
	, no_winner('N')
	, answer(' ')
	, max_pos(9)
	, min_pos(1)
{
	// fill the vector with spaces
	for (int i = 0; i < 9; ++i)
	{
		board.push_back(empty);
	}
}

void TicTacToe::displayInfo()
{
	cout << "To make your move enter a number (1 - 9), \n";

	cout << "7 | 8 | 9\n";
	cout << "---------\n";
	cout << "4 | 5 | 6\n";
	cout << "---------\n";
	cout << "1 | 2 | 3\n\n";
}

void TicTacToe::displayBoard()
{
	cout << "\n\t" << board[6] << " | " << board[7] << " | " << board[8];
	cout << "\n\t" << "---------";
	cout << "\n\t" << board[3] << " | " << board[4] << " | " << board[5];
	cout << "\n\t" << "---------";
	cout << "\n\t" << board[0] << " | " << board[1] << " | " << board[2];
	cout << endl << endl;
}

void TicTacToe::Answer()
{
	do
	{
		cout << this->question;
		cin >> this->answer;

		// transform the input to lower case
		answer = towlower(answer);

	} while (answer != 'y' && answer != 'n');
}

char TicTacToe::playerOneSign(const char X, const char O)
{
	if (this->answer == 'y')
	{
		return X;
	}
	else
	{
		return O;
	}
}

char TicTacToe::PlayerTwoSign(const char X, const char O)
{
	char getPlayerOneSign = playerOneSign(X, O);

	if (getPlayerOneSign == X)
	{
		return O;
	}
	else
	{
		return X;
	}
}

bool TicTacToe::isLegalMove(int move)
{
	return (board[move - 1] == empty);
}
char TicTacToe::winner()
{
	const int MAX_ROWS = 8;
	//all possible winning pairs
	const int WINNING_PAIRS[MAX_ROWS][3] = { { 0, 1, 2 },
	{ 3, 4, 5 },
	{ 6, 7, 8 },
	{ 0, 3, 6 },
	{ 1, 4, 7 },
	{ 2, 5, 8 },
	{ 2, 4, 6 },
	{ 0, 4, 8 }
	};
	// check for 3 equal values
	for (int row = 0; row < MAX_ROWS; ++row)
	{
		if ((board[WINNING_PAIRS[row][0]] != empty) &&
			(board[WINNING_PAIRS[row][0]] == board[WINNING_PAIRS[row][1]]) &&
			(board[WINNING_PAIRS[row][1]] == board[WINNING_PAIRS[row][2]]))
		{
			return board[WINNING_PAIRS[row][0]];
		}
	}
	// return if the game is draw
	if (count(board.begin(), board.end(), empty) == 0)
	{
		return draw;
	}
	return no_winner;
}
//Player one
void TicTacToe::playerOne(const char X, const char O)
{
	int move;

	do
	{
		cout << "Player one choose a position: ";
		cin >> move;
		if (!cin)
		{
			cerr << "\nWrong input !\n";
			cin.clear();
			cin.ignore();
		}
	} while (move > max_pos || move < min_pos || !isLegalMove(move));
	board[move - 1] = playerOneSign(X, O);
}
//Player two
void TicTacToe::PlayerTwo(const char X, const char O)
{
	int move;
	do
	{
		cout << "Player two choose a position: ";
		cin >> move;
		if (!cin)
		{
			cerr << "\nWrong input !\n";
			cin.clear();
			cin.ignore();
		}
	} while (move > max_pos || move < min_pos || !isLegalMove(move));
	board[move - 1] = PlayerTwoSign(X, O);;
}

void TicTacToe::displayWinner(const char X, const char O)
{
	char plaOne = playerOneSign(X, O);
	char plaTwo = PlayerTwoSign(X, O);

	if (plaOne == winner())
	{
		cout << "\nPlayer one you've won ! :) " << endl;
		cout << "Player two you've lost ! :( " << endl;
	}
	else if (plaTwo == winner())
	{
		cout << "\nPlayer two you've won ! :) " << endl;
		cout << "Player one you've lost ! :( " << endl;
	}
	else
	{
		cout << "The game is DRAW !" << endl;
	}
}

bool TicTacToe::isBoardFull()
{
	if (count(board.begin(), board.end(), empty) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}