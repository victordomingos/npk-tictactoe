#pragma once


void newGame(void);
void displayBoard();
void displayBoard(string player1, string player2, int player1_score, int player2_score);
bool isBoardFull(void);


// Initializes an empty board
void newGame()
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
			board[i][j] = ' ';
	}
}


// Display board without score
void displayBoard()
{
	for (size_t i = 0; i < 5; i++)
		std::cout << "\n\n";

	for (size_t i = 0; i < 3; i++)
	{
		std::cout << "   " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << endl;
		if (i < 2)
			std::cout << "  -----------\n";
	}
	std::cout << std::endl;
}


// Display board with score
void displayBoard(string player1, string player2, int player1_score, int player2_score)
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
bool isBoardFull()
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			if (board[i][j] == ' ')
				return false;
		}
	}
	return true;
}
