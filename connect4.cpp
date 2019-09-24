#include "connect4.h"
#include <iostream>
#include <ctime>

using namespace std;


int main()
{
	srand(time(NULL)); //random
	connect4 game; //declare class

	//variables
	int player, board, rows, col;
	bool Over = false;
	bool Move = false;
	char player1, player2, AI;

	//promt playerss
	cout << "Welcome to connect4 game!" << endl;
	cout << "How many players? ";
	cin >> player;
	cout << endl;

	if (player == 2)
	{
		player1 = 'X';
		player2 = 'O';
	}
	if (player == 1)
	{
		player1 = 'X';
		AI = 'O';
	}

	cout << "Play standard game (press 1) or custom board (press 2): ";
	cin >> board;
	cout << endl;
	if (board == 1)
	{
		if (player == 1) //Player vs AI
	{
		while (Over == false)
		{
			if (player == 1)
			{
				cout << "It is " << player1 << "'s turn: \n" << "Column: ";
				cin >> col;
				game.makeMove('X', col);
				Over = game.gameOver();
				player = 2;
			}
			else
			{
				cout << "It is " << AI << "'s turn: \n";
				game.makeMove('O', game.GetAIMove());
				Over = game.gameOver();
				player = 1;
			}
		}
	}
	if (player == 2)
	{
		while (Over == false)
		{
			if (player == 2)
			{
				cout << "It is " << player1 << "'s turn: \n" << "Column: ";
				cin >> col;
				game.makeMove('X', col);
				Over = game.gameOver();
				player = 1;
			}
			else
			{
				cout << "It is " << player2 << "'s turn: \n" << "Column: ";
				cin >> col;
				game.makeMove('O', col);
				Over = game.gameOver();
				player = 2;
			}
		}
	}
	}

	if (board == 2) //custom board
	{
		cout << "Rows: ";
		cin >> rows;
		cout << "columns: ";
		cin >> col;
		if (rows < 4 || col < 4)
		{
			cout << "Please Input valid board size";
		}
		else
		{
			connect4 custom(rows, col);
			if (player == 1) //Player vs AI
			{
				while (Over == false)
				{
					if (player == 1)
					{
						cout << "It is " << player1 << "'s turn: \n" << "Column: ";
						cin >> col;
						custom.makeMove('X', col);
						Over = custom.gameOver();
						player = 2;
					}
					else
					{
						cout << "It is " << AI << "'s turn: \n";
						custom.makeMove('O', custom.GetAIMove());
						Over = custom.gameOver();
						player = 1;
					}
				}
			}
			if (player == 2)
			{
				while (Over == false)
				{
					if (player == 2)
					{
						cout << "It is " << player1 << "'s turn: \n" << "Column: ";
						cin >> col;
						custom.makeMove('X', col);
						Over = custom.gameOver();
						player = 1;
					}
					else
					{
						cout << "It is " << player2 << "'s turn: \n" << "Column: ";
						cin >> col;
						custom.makeMove('O', col);
						Over = custom.gameOver();
						player = 2;
					}
				}
			}
		}
	}


	return 0;
}
