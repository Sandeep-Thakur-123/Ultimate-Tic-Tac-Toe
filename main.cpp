#include <iostream>
#include "TicTacToe.h"

using namespace std;

// ANSI escape codes for basic console styling (Works in modern Windows Terminal)
const string RESET = "\033[0m";
const string GREEN = "\033[32m";
const string CYAN = "\033[36m";

int main() {
    TicTacToe game;
    int choice;

    do {
        cout << "\n" << CYAN << "========================================" << RESET << "\n";
        cout << GREEN << "      ULTIMATE TIC TAC TOE" << RESET << "\n";
        cout << CYAN << "========================================" << RESET << "\n";
        cout << "1. Play against Unbeatable AI (Minimax)\n";
        cout << "2. Play Local Multiplayer (PvP)\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            choice = 0; // Trigger invalid choice
        }

        switch (choice) {
            case 1:
                game.playAgainstAI();
                break;
            case 2:
                game.playMultiplayer();
                break;
            case 3:
                cout << "Thanks for playing! Goodbye.\n";
                break;
            default:
                cout << "Invalid choice. Please enter 1, 2, or 3.\n";
        }
    } while (choice != 3);

    return 0;
}
