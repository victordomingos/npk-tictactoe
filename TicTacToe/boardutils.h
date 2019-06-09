#pragma once

#include <string>

using namespace std;

void newGame(char board[3][3]);
void displayBoard(char board[3][3]);
void displayBoard(char board[3][3], string player1, string player2, int player1_score, int player2_score);
bool isBoardFull(char board[3][3]);
bool isBoardEmpty(char board[3][3]);

