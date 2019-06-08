#include <iostream>
#include <Windows.h>

#include "boardutils.h"
#include "gamemoves.h"


// Check if the board contains a winning trio of X's or O's (1 for true, 0 for false)
// If not winning but board is full, then we have a draw (-1).
int check_win_move(char board[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		// Check all horizontal lines
		if (board[i][0] != ' ' and board[i][0] == board[i][1] and board[i][0] == board[i][2])
			return 1; //win!!

		// Check all vertical lines
		if (board[0][i] != ' ' and board[0][i] == board[1][i] and board[0][i] == board[2][i])
			return 1; //win!!
	}

	// Check both diagonal lines
	if (board[0][0] != ' ' and board[0][0] == board[1][1] and board[1][1] == board[2][2])
		return 1; //win!!
	if (board[2][0] != ' ' and board[2][0] == board[1][1] and board[1][1] == board[0][2])
		return 1; //win!!

	if (isBoardFull(board))
		return -1; // Draw...

	return 0; // not winning yet...
}


bool makeMove(char board[3][3], int position, char symbol)
{
	int line, col;

	line = (position - 1) / 3;
	col = (position - 1) % 3;

	//cout << "L/C:" << line << "/" << col << endl;

	if (board[line][col] == ' ')
	{
		board[line][col] = symbol;
		return true;
	}
	else
	{
		return false;
	}
}