//===========================================
// Program Lab 2
// 1-31-2018
// Edgar Hernandez
//===========================================


#include <iostream>
#include <vector>
#include <limits>

#include "TicTacToe.h"

using namespace std;


const char X = 'X';
const char O = 'O';

int main()
{
	int xi;

	TicTacToe game;
	game.displayInfo();
	game.Answer();

	while (game.winner() == game.noWinner())
	{
		if (game.getAnswer() == 'y')
		{
			game.displayBoard();
			game.playerOne(X, O);
			if (game.isBoardFull()) { break; };
			if (game.winner() == game.playerOneSign(X, O)) 
			{
				game.displayBoard();
				break; 
			};
			game.displayBoard();
			game.PlayerTwo(X, O);
		}
		else
		{
			game.PlayerTwo(X, O);
			game.displayBoard();
			if (game.isBoardFull()) { break; };
			if (game.winner() == game.PlayerTwoSign(X, O)) 
			{ 
				game.displayBoard();
				break; 
			};
			game.playerOne(X, O);
			game.displayBoard();
		}
	}
	game.displayWinner(X, O);
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();

	cin >> xi;
}