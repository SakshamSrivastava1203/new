#include <stdio.h>
char board[3][3];
char currentPlayer;
void initializeBoard() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
    currentPlayer = 'O';  // Player 1 starts with 'O'
}
void displayBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}
int checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) return 1;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer) return 1;
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) return 1;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer) return 1;
    return 0;
}
int checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return 0;
        }
    }
    return 1;
}
void switchPlayer() {
    currentPlayer = (currentPlayer == 'O') ? 'X' : 'O';
}
int isValidMove(int row, int col) {
    return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ';
}
void makeMove() {
    int row, col;
    printf("Player %c, enter your move (row and column): ", currentPlayer);
    scanf("%d %d", &row, &col);
    if (isValidMove(row - 1, col - 1)) {
        board[row - 1][col - 1] = currentPlayer;
    } else {
        printf("Invalid move! Try again.\n");
        makeMove();
    }
}
int main() {
    initializeBoard();
    printf("Welcome to Tic Tac Toe!\n");
    printf("Player 1 is 'O', Player 2 is 'X'.\n");
    displayBoard();
    while (1) {
        makeMove();
        displayBoard();
        if (checkWin()) {
            printf("Player %c wins! Congratulations!\n", currentPlayer);
            break;
        }
        if (checkDraw()) {
            printf("It's a draw! Well played both.\n");
            break;
        }
        switchPlayer();
    }
    return 0;
}