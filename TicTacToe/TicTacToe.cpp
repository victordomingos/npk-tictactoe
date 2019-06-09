// TicTacToe
// 2019-05
// Victor Domingos

#include <iostream>
#include <string>
#include <conio.h>
#include <time.h>
#include <windows.h>

#include "consolestuff.h"
#include "boardutils.h"
#include "gamemoves.h"
#include "basicai.h"

using namespace std;

int main()
{
	const string ai_names[9] = { "Elisa", "Sophie", "HAL 2000", "VIKI", "Sonny",
								 "Tardis", "KITT", "R2D2", "3PO" };
	char board[3][3] = { { ' ', ' ', ' '}, { ' ', ' ', ' '}, { ' ', ' ', ' '}, };
    char key = '-';
	char smartness = 2;  // TODO: make this variable and progressive.
    int position;
    int current_player;
    char current_player_symbol;
    int using_AI = 0;
	string players[3] = { "" };
    int player1score = 0;
    int player2score = 0;
    int win_status;
    bool change_turn = false;

    srand(time(NULL));

    displayWelcome();

    cout << "\nPlease enter first player's name:\n -> ";
    getline(cin, players[1]);
    cout << "\nHi, " << players[1] << "!\n\n";


    using_AI = choose_opponent();
    if (using_AI == -1)
    {
        displayQuitMessage();
        return 0;
    }
    else if (using_AI == -2)
    {
        cout << "\n\nPlease enter the second player's name:\n -> ";
        getline(cin, players[2]);
        cout << "\nHi, " << players[2] << "!\n\n";
    }
    else
    {
        players[2] = ai_names[using_AI];
        cout << "\n\nPlaying against " << players[2] << ", one of most famous TicTactToe players in the world...\n" << endl;
    }


    // Determine which player should use X or O
    if (rand() % 2 == 0)
        current_player_symbol = 'X';
    else
        current_player_symbol = 'O';

    // Determine who plays first
    current_player = rand() % 2 + 1;
	cout << endl << players[current_player] << " plays first (" << current_player_symbol << ").\n";
    waitForAnyKey();

    // Start game loop
    do
    {
		clearScreen();
		displayHeader();
		displayBoard(board, players[1], players[2], player1score, player2score);

        // if current player is human, ask for position
        // if not, generate an inteligent move.
        if (current_player == 1)
            cout << "\n " << players[1] << " (1-9)? ";
        else if (current_player == 2 and using_AI == -2)
            cout << "\n " << players[2] << " (1-9)? ";

        // AI player is always number 2. Is it the current player?
        if ((using_AI >= 1) and (current_player == 2))
        {
            Sleep(rand() % 3000 + 500);
            if (makeAImove(board, current_player_symbol, smartness))
            {
                change_turn = true;
                win_status = check_win_move(board);

				if (win_status == 0)
					{ change_turn = true; }
				else
				{
					change_turn = false;
					clearScreen();
					displayHeader();
					displayBoard(board, players[1], players[2], player1score, player2score);

					if (win_status == 1)
					{
						if (current_player == 1)
						{
							player1score++;
							smartness++;
						}
						else
							player2score++;

						displayWinMessage(players[current_player]);
					}
					else // we have a draw
						{ displayDrawMessage(); }

					waitForAnyKey();
					newGame(board);
				}
            }
            // if board is full we should not be here in the first place:
            else
                cout << "\n\n\"Something wrong is not right\" (J.A.)\n";
        }
        else
        {
            fflush(stdin);
            key = _getche();		
			
            switch (key)
            {
            case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                position = key - '0';  // convert a numeric character to int using its 'face value'
				if (makeMove(board, position, current_player_symbol))
				{
					win_status = check_win_move(board);
					if (win_status == 0)
						{ change_turn = true;}
					else
					{
						change_turn = false;
						clearScreen();
						displayHeader();
						displayBoard(board, players[1], players[2], player1score, player2score);

						if (win_status == 1)
						{
							if (current_player == 1) 
								player1score++;
							else 
								player2score++;

							displayWinMessage(players[current_player]);
						}
						else // we have a draw
							displayDrawMessage();

						waitForAnyKey();
						newGame(board);
					}
                }
                else 
				{
					change_turn = false;
					cout << "\nThat position is already taken. Please play again.\n";
					Sleep(2000);
				}
                break;

            default:
				if (key == 27)
				{
					displayQuitMessage();
					return 0;
				}

                change_turn = false;
                cout << "\n Please choose an empty position, between 1 and 9.";
                break;
            }
        }

        if (change_turn)
        {
            if (current_player == 1)
                current_player = 2;
            else
                current_player = 1;

            if (current_player_symbol == 'X')
                current_player_symbol = 'O';
            else
                current_player_symbol = 'X';
        }

    } while (key != 27);

    displayQuitMessage();
    return 0;
}