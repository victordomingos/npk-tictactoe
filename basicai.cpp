#include <iostream>

#include "basicai.h"
#include "boardutils.h"
#include "gamemoves.h"

using namespace std;

/* Check if the board is not full yet, then generate coordinates
   for a new (presumably intelligent) AI move, placing the supplied symbol
   in that position of the board.
   Returns a boolean indicating if the move was successful.
*/
bool makeAImove(char board[3][3], char symbol)
{
	int position;

	if (isBoardFull(board))
	{
		cout << "The board is full, no more moves available.";
		return false;
	}

	do
	{
		position = rand() % 9 + 1;  // Pretty intelligent algorithm, hum?
	} while (not makeMove(board, position, symbol));

	return true;
}

