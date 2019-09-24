#pragma once
#include<iostream>

using namespace std;

class connect4
{
private:
	char ** board;
	int col;
	int row;
public:
	bool GameOver = false;
	int totalMove = 0;
	char win;
	int winningCount = 0;
	connect4() //standard game
	{
		row = 6;
		col = 7;
		board = new char*[row];
		for (int i = 0; i < row; i++)
		{
			board[i] = new char[col];
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				board[i][j] = ' ';
			}
		}
	}
	connect4(int x, int y) //custom board
	{
		row = x;
		col = y;
		board = new char*[row];
		for (int i = 0; i < row; i++)
		{
			board[i] = new char[col];
		}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				board[i][j] = ' ';
			}

		}
	}
	bool gameOver() //gameover 
	{
		if (GameOver == true)
		{
			if (totalMove == row * col)
			{
				cout << "Tie game" << endl;
			}
			else
			{
				cout << "The winner is " << Winner() << endl;
			}
			return GameOver;
		}
		else
		{
			return false;
		}
		return GameOver;
	}
	char Winner() //return winner
	{
		return win;
	}
	void DrawBoard() //draw board
	{
		cout << "    ";
		for (int i = 0; i < col; i++)
		{
			cout << i << " ";
		}
		cout << endl;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (j == 0)
				{
					cout << i << " " << "|";
				}
				cout << board[i][j] << " ";
			}
			cout << "|";
			cout << endl;
		}
		cout << "  ";
		for (int i = 0; i <= col; i++)
		{
			cout << " _";
		}
		cout << endl;
	}
	//make move//
	bool makeMove(char c, int y)
	{
		int index;
		int rowindex;
		bool makeMove = false;

		for (int i = row - 1; i >= 0; i--)
		{
			if (board[i][y] == ' ')
			{
				board[i][y] = c;
				makeMove = true;
				index = i;
				rowindex = y;
				break;
			}
		}
		if (y < 0 || y >= col && makeMove ==false)
		{
			cout << "Invalid Location" << endl;
			cout << endl;
			cout << "Enter column: ";
			cin >> y;
			for (int i = row - 1; i >= 0; i--)
			{
				if (board[i][y] == ' ')
				{
					board[i][y] = c;
					makeMove = true;
					index = i;
					rowindex = y;
					break;
				}
			}
			DrawBoard();
			return makeMove;
		}
		if (makeMove == false)
		{
			cout << "Row is already full";
			cout << "Enter column: ";
			cin >> y;
			for (int i = row - 1; i >= 0; i--)
			{
				if (board[i][y] == ' ')
				{
					board[i][y] = c;
					makeMove = true;
					index = i;
					rowindex = y;
					break;
				}
			}
			DrawBoard();
			return makeMove;
		}

		DrawBoard();
		if (makeMove == true)
		{
			//check right and left
			for (int i = rowindex; i >= 0; i--)//check left
			{
				if (board[index][i] == c)
				{
					winningCount++;
				}
				else
				{
					winningCount = 0;
					break;
				}
				if (winningCount == 4)
				{
					break;
				}
			}
			//check winner//
			if (winningCount == 4)
			{
				win = c;
				GameOver = true;
			}
			else
			{
				winningCount = 0;
			}
			for (int i = rowindex; i < col; i++)//check right
			{
				if (board[index][i] == c)
				{
					winningCount++;
				}
				else
				{
					winningCount = 0;
					break;
				}
				if (winningCount == 4)
				{
					break;
				}
			}
			//check winner//
			if (winningCount == 4)
			{
				win = c;
				GameOver = true;
			}
			else
			{
				winningCount = 0;
			}
			//check up and down
			for (int i = index; i >= 0; i--)//check up
			{
				if (board[i][y] == c)
				{
					winningCount++;
				}
				else
				{
					winningCount = 0;
					break;
				}
				if (winningCount == 4)
				{
					break;
				}
			}
			//check winner//
			if (winningCount == 4)
			{
				win = c;
				GameOver = true;
			}
			else
			{
				winningCount = 0;
			}
			for (int i = index; i < row; i++)//check down
			{
				if (board[i][y] == c)
				{
					winningCount++;
				}
				else
				{
					winningCount = 0;
					break;
				}
				if (winningCount == 4)
				{
					break;
				}
			}
			//check winner//
			if (winningCount == 4)
			{
				win = c;
				GameOver = true;
			}
			else
			{
				winningCount = 0;
			}
			//check diagonals//
			for (int i = index, j = rowindex; i < row && j >= 0; i++, j--) // down left
			{
				if (board[i][j] == c)
				{
					winningCount++;
				}
				else
				{
					winningCount = 0;
					break;
				}
				if (winningCount == 4)
				{
					break;
				}
			}
			//check winner//
			if (winningCount == 4)
			{
				win = c;
				GameOver = true;
			}
			else
			{
				winningCount = 0;
			}
			for (int i = index, j = rowindex; i < row && j < col; i++, j++) // down right
			{
				if (board[i][j] == c)
				{
					winningCount++;
				}
				else
				{
					winningCount = 0;
					break;
				}
				if (winningCount == 4)
				{
					break;
				}
			}
			//check winner//
			if (winningCount == 4)
			{
				win = c;
				GameOver = true;
			}
			else
			{
				winningCount = 0;
			}
			for (int i = index, j = rowindex; i >= 0 && j >= 0; i--, j--) // up left
			{
				if (board[i][j] == c)
				{
					winningCount++;
				}
				else
				{
					winningCount = 0;
					break;
				}
				if (winningCount == 4)
				{
					break;
				}
			}
			//check winner//
			if (winningCount == 4)
			{
				win = c;
				GameOver = true;
			}
			else
			{
				winningCount = 0;
			}
			for (int i = index, j = rowindex; i >= 0 && j < col; i--, j++) // up right
			{
				if (board[i][j] == c)
				{
					winningCount++;
				}
				else
				{
					winningCount = 0;
					break;
				}
				if (winningCount == 4)
				{
					break;
				}
			}
			//check winner//
			if (winningCount == 4)
			{
				win = c;
				GameOver = true;
			}
			else
			{
				winningCount = 0;
			}
		}
		totalMove++;
		return makeMove;
	}
	//AI move
	int GetAIMove()
	{
		int column;
		column = rand() % (row - 1);
		totalMove++;
		return column;
	}
};