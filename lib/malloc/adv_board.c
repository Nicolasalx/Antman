/*
** EPITECH PROJECT, 2022
** adv_board
** File description:
** adv_board
*/

#include <stdlib.h>

char **adv_board(int nb_line, int *lines_size)
{
    int i;
    int j;
    char **board = malloc(sizeof(char *) * (nb_line + 1));
    for (i = 0; i < nb_line; ++i) {
        board[i] = malloc(sizeof(char) * (lines_size[i] + 1));
        for (j = 0; j < lines_size[i]; ++j) {
            board[i][j] = '\0';
        }
        board[i][j] = '\0';
    }
    board[i] = NULL;
    return board;
}
