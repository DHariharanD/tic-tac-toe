#include <stdio.h>

#define SIZE 3

// Function to print the Tic Tac Toe board
void printBoard(char board[SIZE][SIZE]){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < SIZE - 1) {
            printf("---|---|---\n");
        }
    }
}

// Function to check if a player has won
int checkWin(char board[SIZE][SIZE], char player) {
    // Check rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < SIZE; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}

int main() {
    char board[SIZE][SIZE];
    int player = 1;
    int row, col;

    // Initialize the board with empty spaces
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '-';
        }
    }

    // Game loop
    while (1) {
        printBoard(board);
        printf("Player %d, enter your move (row and column): ", player);
        scanf("%d%d", &row, &col);
        row--;
        col--;
        if (board[row][col] != '-') {
            printf("That space is already taken. Try again.\n");
            continue;
        }
        board[row][col] = player == 1 ? 'X' : 'O';
        if (checkWin(board, player == 1 ? 'X' : 'O')) {
            printBoard(board);
            printf("Player %d wins!\n", player);
            break;
        }
        if (checkWin(board, 'T')) {
            printBoard(board);
            printf("It's a tie!\n");
            break;
        }
        player = player == 1 ? 2 : 1;
    }

    return 0;
}