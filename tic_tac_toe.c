#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Constants for board size
#define SIZE 3

// Function prototypes
void initializeBoard(char board[][SIZE]);
void drawBoard(char board[][SIZE]);
bool isMoveValid(char board[][SIZE], int row, int col);
bool checkWin(char board[][SIZE], char symbol);
bool isBoardFull(char board[][SIZE]);
void makeSystemMove(char board[][SIZE], char symbol);
void clearScreen();

int main() {
    char board[SIZE][SIZE];
    int row, col;
    char currentPlayer = 'X';
    bool gameover = false;
    bool playerTurn = true; // true for player, false for system
    
    // Initialize the board
    initializeBoard(board);
    
    printf("Welcome to Tic-Tac-Toe!\n");
    printf("Player 1 (X) - Player 2 (O)\n\n");
    
    // Game loop
    while (!gameover) {
        // Clear screen
        clearScreen();
        
        // Draw the board
        drawBoard(board);
        
        // Player's turn
        if (playerTurn) {
            printf("Player %c's turn. Enter row (1-%d) and column (1-%d): ", currentPlayer, SIZE, SIZE);
            scanf("%d %d", &row, &col);
            
            // Convert to 0-based index
            row--;
            col--;
            
            // Validate move
            if (isMoveValid(board, row, col)) {
                board[row][col] = currentPlayer;
                playerTurn = !playerTurn; // switch turns
            } else {
                printf("Invalid move. Please try again.\n");
                continue; // repeat player's turn
            }
        }
        // System's turn
        else {
            printf("System's turn (O):\n");
            makeSystemMove(board, 'O');
            playerTurn = !playerTurn; // switch turns
        }
        
        // Check for win or draw
        if (checkWin(board, currentPlayer)) {
            clearScreen();
            drawBoard(board);
            printf("Player %c wins!\n", currentPlayer);
            gameover = true;
        } else if (isBoardFull(board)) {
            clearScreen();
            drawBoard(board);
            printf("It's a draw!\n");
            gameover = true;
        }
    }
    
    // Prompt for exit
    printf("\nPress any key to exit...\n");
    getchar(); // Consume newline from previous scanf
    getchar(); // Wait for user input to exit
    
    return 0;
}

// Function to initialize the board with empty spaces
void initializeBoard(char board[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to draw the current state of the board
void drawBoard(char board[][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) {
            for (int k = 0; k < SIZE * 4 - 1; k++) {
                printf("-");
            }
            printf("\n");
        }
    }
    printf("\n");
}

// Function to check if a move is valid
bool isMoveValid(char board[][SIZE], int row, int col) {
    return (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ');
}

// Function to check if a player has won
bool checkWin(char board[][SIZE], char symbol) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) return true;
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) return true;
    }
    
    // Check diagonals
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) return true;
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) return true;
    
    return false;
}

// Function to check if the board is full
bool isBoardFull(char board[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

// Function to make a random move for the system
void makeSystemMove(char board[][SIZE], char symbol) {
    int row, col;
    do {
        row = rand() % SIZE;
        col = rand() % SIZE;
    } while (!isMoveValid(board, row, col));
    
    board[row][col] = symbol;
}

// Function to clear the screen based on system command
void clearScreen() {
    // Clear screen command for Windows and Unix-like systems
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
