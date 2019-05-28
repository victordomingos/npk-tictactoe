#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void clearScreen(void)
{
	/*
	for (size_t i = 0; i < 5; i++)
		cout << "\n\n\n\n\n\n\n\n\n\n";
	*/
	system("cls");
}


// Waits for any key press, then clears the screen
void waitForAnyKey()
{
	cout << "\nPress any key to continue...";
	fflush(stdin); _getch();
	clearScreen();
}


void displayWelcome(void)
{
	char example_board[3][3] = { { '1', '2', '3'},
								 { '4', '5', '6'},
								 { '7', '8', '9'}, };

	clearScreen();
	cout << "\n\nWelcome to yet another incredible TicTacToe game!\n\n\n\n";

	Sleep(1000);
	cout << "Here's how it works:\n\n\n";
	Sleep(500);		cout << "  - Each player either gets a bag full of O's, or a bag full of X's.\n\n";
	Sleep(200);		cout << "  - At each turn, the player chooses an empty board position for the\n    next move.\n\n";
	Sleep(200);		cout << "  - The first player who manages to get 3 aligned positions wins.\n\n";
	Sleep(200);		cout << "  - Those 3 positions can be aligned in vertical, horizontal or diagonal\n    directions.\n\n";

	Sleep(800);
	waitForAnyKey();

	cout << "\n\nJust one more thing:\n\n";
	Sleep(500);
	cout << " - Each board postion has its own number. So, in order to make a move,\n   you just need to press the corresponding key.\n\n";
	Sleep(800);
	cout << "Now, let's see which number corresponds to each position in the board:\n\n";
	cout << "   1 | 2 | 3\n";
	cout << "  -----------\n";
	cout << "   4 | 5 | 6\n";
	cout << "  -----------\n";
	cout << "   7 | 8 | 9\n\n\n";

	Sleep(800);
	waitForAnyKey();
}


void displayHeader()
{
	// Welcome text
	cout << "\n_ _ _ The amazing NPK TicTacToe game! _ _ _\n\n\n\n";
}


void displayWinMessage(string player_name)
{
	cout << "\n\n" << player_name << " has won this round!\n";
	Sleep(1000);
}


void displayDrawMessage()
{
	cout << "\n\nNobody has won this round... We have a draw.\n";
	Sleep(1000);
}


void displayQuitMessage(void)
{
	cout << "\n\nSee you soon!\n\n\n";
	Sleep(1000);
}


// Game type menu (AI or Human opponent?)
// Returns a random number (to select the AI character name)
// or -2 to proceeed with another human player
// or -1 to quit the game.
int choose_opponent(void)
{
	char k;

	do
	{
		cout << "Please chose the type of your opponent:\n";
		cout << "  A) A.I. (computer)\n";
		cout << "  H) Human\n\n? ";

		fflush(stdin);
		k = _getche();

		switch (toupper(k))
		{
		case 'A':
			return rand() % 9;
			break;
		case 'H':
			return -2;
			break;
		default:
			if (k == 27)
				return -1;
			break;
		}
	} while (k != 27);

	return -1;
}
