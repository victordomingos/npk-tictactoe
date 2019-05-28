#pragma once

void clearScreen(void);
void displayWelcome(void);
void displayHeader(void);
void displayWinMessage(std::string player_name);
void displayDrawMessage();
void displayQuitMessage(void);
void waitForAnyKey();

int choose_opponent(void);