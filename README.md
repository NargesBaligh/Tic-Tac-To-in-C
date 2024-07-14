# Tic-Tac-Toe Game in C
This is a text-based implementation of the classic Tic-Tac-Toe game in C. Players can compete against each other, and the second player is simulated by the system making random moves.


![image](https://github.com/user-attachments/assets/d33f09fa-700e-4da7-b7b6-c7469d2f1f86)


# Features
Players take turns entering their moves ('X' for Player 1 and 'O' for the system).
After each move, the screen is cleared to display the updated board.
The game checks for a win condition or a draw after each move.
Players are prompted to press any key to exit after the game concludes.
How to Play
Compile: Save the code in a file (e.g., tic_tac_toe.c) and compile it using a C compiler like gcc:

# Complie code
gcc -o tic_tac_toe tic_tac_toe.c


# Game Rules:

The game starts with an empty 3x3 board.
Player 1 (X) goes first and enters their move by specifying the row (1-3) and column (1-3).
The system (Player 2, O) then makes a random move on its turn.
The game continues until a player gets three of their symbols in a row, column, or diagonal, or the board fills up with no winner.
After the game ends, press any key to exit the terminal.
