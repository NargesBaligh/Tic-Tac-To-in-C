#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

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
            
            row--;
            col--;
            
            if (isMoveValid(board, row, col)) {
                board[row][col] = currentPlayer;
                playerTurn = !playerTurn; // switch turns
            } else {
                printf("Invalid move. Please try again.\n");
                continue; // repeat player's turn
            }
        }
        else {
            printf("System's turn (O):\n");
            makeSystemMove(board, 'O');
            playerTurn = !playerTurn; // switch turns
        }
        
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
    
    printf("\nPress any key to exit...\n");
    getchar(); // Consume newline from previous scanf
    getchar(); // Wait for user input to exit
    
    return 0;
}

void initializeBoard(char board[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

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

bool isMoveValid(char board[][SIZE], int row, int col) {
    return (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ');
}

bool checkWin(char board[][SIZE], char symbol) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) return true;
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) return true;
    }
    
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) return true;
    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) return true;
    
    return false;
}

bool isBoardFull(char board[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

void makeSystemMove(char board[][SIZE], char symbol) {
    int row, col;
    do {
        row = rand() % SIZE;
        col = rand() % SIZE;
    } while (!isMoveValid(board, row, col));
    
    board[row][col] = symbol;
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
