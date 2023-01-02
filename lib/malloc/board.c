/*
** EPITECH PROJECT, 2022
** board
** File description:
** malloc_a_board
*/

#include <stdlib.h>

char **malloc_board(int nb_line, int size_line)
{
    int i;
    int j;
    char **board = malloc(sizeof(char *) * (nb_line + 1));
    for (i = 0; i < nb_line; ++i) {
        board[i] = malloc(sizeof(char) * (size_line + 1));
        for (j = 0; j < size_line; ++j) {
            board[i][j] = '\0';
        }
        board[i][j] = '\0';
    }
    board[i] = NULL;
    return board;
}

void free_board(char **board, int nb_line)
{
    int i;
    for (i = 0; i < nb_line; ++i) {
        free(board[i]);
    }
    free(board);
}
