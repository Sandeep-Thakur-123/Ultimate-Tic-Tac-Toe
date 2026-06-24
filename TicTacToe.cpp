#include "TicTacToe.h"
#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

// ANSI Color Codes
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string BLUE = "\033[34m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";

TicTacToe::TicTacToe() {
    resetBoard();
}

void TicTacToe::resetBoard() {
    char initChar = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = initChar++;
        }
    }
}

void TicTacToe::printBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'X') {
                cout << " " << RED << board[i][j] << RESET << " ";
            } else if (board[i][j] == 'O') {
                cout << " " << BLUE << board[i][j] << RESET << " ";
            } else {
                cout << " " << board[i][j] << " ";
            }
            if (j < 2) cout << "|";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

bool TicTacToe::checkWin(char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool TicTacToe::checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

bool TicTacToe::isValidMove(int row, int col) {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] != 'X' && board[row][col] != 'O');
}

int TicTacToe::minimax(bool isMaximizing) {
    if (checkWin(aiPlayer)) return 10;
    if (checkWin(humanPlayer)) return -10;
    if (checkDraw()) return 0;

    if (isMaximizing) {
        int bestScore = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != 'X' && board[i][j] != 'O') {
                    char backup = board[i][j];
                    board[i][j] = aiPlayer;
                    int score = minimax(false);
                    board[i][j] = backup;
                    bestScore = max(score, bestScore);
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != 'X' && board[i][j] != 'O') {
                    char backup = board[i][j];
                    board[i][j] = humanPlayer;
                    int score = minimax(true);
                    board[i][j] = backup;
                    bestScore = min(score, bestScore);
                }
            }
        }
        return bestScore;
    }
}

void TicTacToe::getBestMove(int& bestRow, int& bestCol) {
    int bestScore = -1000;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                char backup = board[i][j];
                board[i][j] = aiPlayer;
                int score = minimax(false);
                board[i][j] = backup;
                if (score > bestScore) {
                    bestScore = score;
                    bestRow = i;
                    bestCol = j;
                }
            }
        }
    }
}

void TicTacToe::playMultiplayer() {
    resetBoard();
    char currentPlayer = 'X';
    bool gameOver = false;

    cout << YELLOW << "--- Multiplayer Mode ---" << RESET << "\n";
    
    while (!gameOver) {
        printBoard();
        int choice;
        cout << "Player " << (currentPlayer == 'X' ? RED : BLUE) << currentPlayer << RESET << ", enter your move (1-9): ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 9) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << YELLOW << "Invalid input. Please enter a number between 1 and 9.\n" << RESET;
            continue;
        }

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (isValidMove(row, col)) {
            board[row][col] = currentPlayer;
            if (checkWin(currentPlayer)) {
                printBoard();
                cout << GREEN << "Player " << currentPlayer << " wins!\n" << RESET;
                gameOver = true;
            } else if (checkDraw()) {
                printBoard();
                cout << YELLOW << "It's a draw!\n" << RESET;
                gameOver = true;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        } else {
            cout << YELLOW << "Spot already taken! Try again.\n" << RESET;
        }
    }
}

void TicTacToe::playAgainstAI() {
    resetBoard();
    humanPlayer = 'X';
    aiPlayer = 'O';
    bool gameOver = false;

    cout << YELLOW << "--- Single Player vs Unbeatable AI ---" << RESET << "\n";

    while (!gameOver) {
        printBoard();
        int choice;
        cout << "Player " << RED << humanPlayer << RESET << ", enter your move (1-9): ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 9) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << YELLOW << "Invalid input. Please enter a number between 1 and 9.\n" << RESET;
            continue;
        }

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (isValidMove(row, col)) {
            board[row][col] = humanPlayer;
            if (checkWin(humanPlayer)) {
                printBoard();
                cout << GREEN << "Congratulations! You win!\n" << RESET;
                gameOver = true;
                continue;
            } else if (checkDraw()) {
                printBoard();
                cout << YELLOW << "It's a draw!\n" << RESET;
                gameOver = true;
                continue;
            }

            cout << "AI is thinking...\n";
            int bestRow, bestCol;
            getBestMove(bestRow, bestCol);
            board[bestRow][bestCol] = aiPlayer;

            if (checkWin(aiPlayer)) {
                printBoard();
                cout << RED << "AI wins! Better luck next time.\n" << RESET;
                gameOver = true;
            } else if (checkDraw()) {
                printBoard();
                cout << YELLOW << "It's a draw!\n" << RESET;
                gameOver = true;
            }
        } else {
            cout << YELLOW << "Spot already taken! Try again.\n" << RESET;
        }
    }
}
