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
	int selectable_positions[4] = { 1, 3, 7, 9 };
	char board_status;

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
		case 2:  // Try to come up with a good first move, then play randomly; 
			board_status = detectFirstMove(board);

			if (board_status == 4 or board_status == 3) // Empty board or first move of opponent at the center - attack on corner!
				position = selectable_positions[(rand() % 4)];
			else if (board_status == 1 or board_status == 2) // First move in a corner or edge - attack on center!
				position = 5;
			else // Not the first move
				position = rand() % 9 + 1;

			break;
		case 3:  // Choose a good first move, and then complete a 2 sequence (if available) to win.
		case 4:  // Choose a good first move, and then complete a 2 sequence (if available), or else try to block a win from the opponent.
		case 5:  // Consider all the previous and come up with an even smarter move.
		default:
			board_status = detectFirstMove(board);

			if (board_status == 4 or board_status == 3) // Empty board or first move of opponent at the center - attack on corner!
				position = selectable_positions[ (rand() % 4) ]; 
			else if (board_status == 1 or board_status == 2) // First move in a corner or edge - attack on center!
				position = 5; 
			else // Not the first move
				position = rand() % 9 + 1;

			break;		
		}
	} while (not makeMove(board, position, symbol));

	return true;
}

