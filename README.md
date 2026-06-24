# 🎮 Ultimate Tic Tac Toe (C++)

An enhanced, console-based Tic Tac Toe game built in C++ featuring an **Unbeatable AI** powered by the **Minimax Algorithm**.

## 🚀 Features
- **Unbeatable AI Mode**: Play against an AI that mathematically calculates every possible future move using the Minimax algorithm. You can draw, but you can never win!
- **Local Multiplayer Mode**: Play against a friend on the same computer.
- **Input Validation**: Robust error handling to prevent crashes from invalid user inputs.
- **Colorful UI**: Utilizes ANSI escape codes for an interactive and visually appealing command-line interface.
- **Clean Object-Oriented Design**: Structured code demonstrating strong C++ OOP principles.

## 🧠 How the AI Works (Minimax Algorithm)
The AI utilizes the **Minimax Algorithm**, a backtracking algorithm commonly used in game theory. It explores all possible future moves on the board, assigning scores to the final outcomes (+10 for AI win, -10 for Player win, 0 for draw). It then recursively chooses the move that maximizes its chances of winning while minimizing the player's chances.

## 🛠️ Getting Started

### Prerequisites
- A C++ compiler (e.g., `g++` via MinGW on Windows, or standard GCC on Linux/Mac).
- A terminal that supports ANSI escape codes (e.g., Windows Terminal, VS Code Terminal, macOS Terminal).

### Running on Windows
If you have `g++` installed, simply double-click the included batch file:
```cmd
build.bat
```

### Manual Compilation
Alternatively, compile using the following command from the terminal:
```bash
g++ main.cpp TicTacToe.cpp -o TicTacToe
./TicTacToe
```

## 📂 Project Structure
* `main.cpp` - Entry point and game menu.
* `TicTacToe.h` - Class definitions and declarations.
* `TicTacToe.cpp` - Core game logic, win conditions, and Minimax AI implementation.
