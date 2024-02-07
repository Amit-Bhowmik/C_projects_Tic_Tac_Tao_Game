#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIDE 3

void showBoard(char board[][SIDE])
{
    printf("\n\n");
    printf("\t\t\t %c | %c | %c \n", board[0][0],
    board[0][1], board[0][2]);
    printf("\t\t\t------------\n");
    printf("\t\t\t %c | %c | %c \n", board[1][0],
    board[1][1], board[1][2]);
    printf("\t\t\t------------\n");
    printf("\t\t\t %c | %c | %c \n\n", board[2][0],
        board[2][1], board[2][2]);
}

void showInstructions()
{
    printf("\t\t\t Tic-Tac-Toe\n\n");
    printf("Choose a cell numbered from 1 to 9 as below "
        "and play\n\n");

    printf("\t\t\t 1 | 2 | 3 \n");
    printf("\t\t\t-----------\n");
    printf("\t\t\t 4 | 5 | 6 \n");
    printf("\t\t\t-----------\n");
    printf("\t\t\t 7 | 8 | 9 \n\n");

    printf("-\t-\t-\t-\t-\t-\t-\t-\t-\t-\n\n");
}

void initialise(char board[][SIDE])
{
    for (int i = 0; i < SIDE; i++) {
        for (int j = 0; j < SIDE; j++)
            board[i][j] = ' ';
    }
}

void declareWinner(char player)
{
    printf("%c has won\n", player);
}

int rowCrossed(char board[][SIDE], char player)
{
    for (int i = 0; i < SIDE; i++) {
        if (board[i][0] == player && board[i][1] == player
            && board[i][2] == player)
            return 1;
    }
    return 0;
}

int columnCrossed(char board[][SIDE], char player)
{
    for (int i = 0; i < SIDE; i++) {
        if (board[0][i] == player && board[1][i] == player
            && board[2][i] == player)
            return 1;
    }
    return 0;
}

int diagonalCrossed(char board[][SIDE], char player)
{
    if ((board[0][0] == player && board[1][1] == player
        && board[2][2] == player)
        || (board[0][2] == player && board[1][1] == player
            && board[2][0] == player))
        return 1;
    return 0;
}

int gameOver(char board[][SIDE], char player)
{
    return (rowCrossed(board, player) || columnCrossed(board, player)
            || diagonalCrossed(board, player));
}

void playTicTacToe()
{
    char board[SIDE][SIDE];

    initialise(board);


    showInstructions();

    char currentPlayer = 'X';

    int moveIndex = 0, x, y;

    while (!gameOver(board, currentPlayer) && moveIndex != SIDE * SIDE) {
        int move;
        printf("Player %c, enter your move (1-9): ", currentPlayer);
        scanf("%d", &move);
        if (move < 1 || move > 9) {
            printf("Invalid input! Please enter a "
                "number between 1 and 9.\n");
            continue;
        }
        x = (move - 1) / SIDE;
        y = (move - 1) % SIDE;
        if (board[x][y] == ' ') {
            board[x][y] = currentPlayer;
            showBoard(board);
            moveIndex++;
            if (gameOver(board, currentPlayer)) {
                declareWinner(currentPlayer);
                return;
            }
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
        else {
            printf("Cell %d is already occupied. Try "
                "again.\n",
                move);
        }
    }

    if (!gameOver(board, currentPlayer) && moveIndex == SIDE * SIDE)
        printf("It's a draw\n");
}

int main()
{
    playTicTacToe();

    return 0;
}
