/*
** EPITECH PROJECT, 2022
** count_lines_size
** File description:
** count_lines_size
*/

#include <stdlib.h>

int *count_lines_size(char *str, int nb_line)
{
    int *lines_size = malloc(sizeof(int) * nb_line);
    int count_lines_size = 0;
    int j = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] != '\n') {
            ++ count_lines_size;
        } else {
            lines_size[j] = count_lines_size;
            ++ j;
            count_lines_size = 0;
        }
    }
    lines_size[j] = count_lines_size;
    return lines_size;
}
