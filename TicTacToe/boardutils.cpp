#include <iostream>
#include <iomanip>

#include "boardutils.h"

using namespace std;


// Initializes an empty board
void newGame(char board[3][3])
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
			board[i][j] = ' ';
	}
}


// Display board without score
void displayBoard(char board[3][3])
{
	for (size_t i = 0; i < 5; i++)
		cout << "\n\n";

	for (size_t i = 0; i < 3; i++)
	{
		cout << "   " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << endl;
		if (i < 2)
			cout << "  -----------\n";
	}
	cout << endl;
}


// Display board with score
void displayBoard(char board[3][3], string player1, string player2, int player1_score, int player2_score)
{
	for (size_t i = 0; i < 5; i++)
		cout << "\n\n";

	for (size_t i = 0; i < 3; i++)
	{
		cout << "   " << board[i][0] << " | " << board[i][1] << " | " << board[i][2];

		if (i == 0)
		{
			cout << "\n  ----------- ";
			cout << "    " << "SCORE:\n";
		}

		else if (i == 1)
		{
			cout << "\n  -----------";
			cout << "     " << setfill('0') << setw(3) << player1_score << " - " << player1 << endl;
		}
		else if (i == 2)
		{
			cout << "      " << setfill('0') << setw(3) << player2_score << " - " << player2 << endl;
		}
	}
	cout << endl;
}



// Returns a boolean indicating if the board has at least one empty position.
bool isBoardFull(char board[3][3])
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
			if (board[i][j] == ' ')  return false;
	}
	return true;
}


// Returns a boolean indicating if the board is still empty.
bool isBoardEmpty(char board[3][3])
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
			if (board[i][j] != ' ')  return false;
	}
	return true;
}

// Returns a char indicating if it was the first move of the oponent and what
// kind of position was played:
// 0 - It was not the first move
// 1 - Corner
// 2 - Edge
// 3 - Center
// 4 - The board is empty!
char detectFirstMove(char board[3][3])
{
	char status = 4;
	
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			if (board[i][j] != ' ')
			{
				if (status == 1 or status == 2 or status == 3)
					return 0; // It was not the first move.
				else if (status == 4)
				{
					if (i == 1 && j == 1)
						status = 3;  // Center
					else if ((i == 0 && j == 0) or (i == 0 && j == 2) or (i == 2 && j == 0) or (i == 2 && j == 2))
						status = 1;  // Corner
					else
						status = 2;  // Edge
				}
			}
		}	
	}
	return status;
}