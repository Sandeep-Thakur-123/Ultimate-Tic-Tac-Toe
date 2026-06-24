#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe {
private:
    char board[3][3];
    char humanPlayer;
    char aiPlayer;
    
    void printBoard();
    void resetBoard();
    bool checkWin(char player);
    bool checkDraw();
    int minimax(bool isMaximizing);
    void getBestMove(int& bestRow, int& bestCol);
    bool isValidMove(int row, int col);

public:
    TicTacToe();
    void playMultiplayer();
    void playAgainstAI();
};

#endif
