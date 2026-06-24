@echo off
echo Compiling Ultimate Tic Tac Toe...
g++ main.cpp TicTacToe.cpp -o TicTacToe.exe
if %ERRORLEVEL% equ 0 (
    echo Compilation successful! Running the game...
    TicTacToe.exe
) else (
    echo Compilation failed. Please ensure g++ is installed and added to your system PATH.
)
pause
