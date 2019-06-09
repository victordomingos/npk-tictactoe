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
bool makeAImove(char board[3][3], char symbol, char smartness)
{
	int position;
	int selectable_positions[4] = { 0, 2, 6, 8 };

	if (isBoardFull(board))
	{
		cout << "The board is full, no more moves available.";
		return false;
	}

	do
	{
		// Make smarter moves as the AI becomes smarter.
		switch (smartness)
		{
		case 1:
			position = rand() % 9 + 1;  // Pretty intelligent algorithm, hum?
			break;
		case 2:
			if (isBoardEmpty(board))
			{
				position = selectable_positions[ (rand() % 4) ];
				cout << "Empty board, using " << position << endl;
				
			}
			else
			{
				cout << "Board not empty!" << endl;
			}
			break;
		default:
			break;
		}

		// Level 2

		// Level 3

		// Level 4

	} while (not makeMove(board, position, symbol));

	return true;
}

