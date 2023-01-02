/*
** EPITECH PROJECT, 2022
** str
** File description:
** malloc_a_str
*/

#include <stdlib.h>

char *malloc_str(int size_str)
{
    int i;
    char *str = malloc(sizeof(char) * (size_str + 1));
    for (i = 0; i < size_str; ++i) {
        str[i] = '\0';
    }
    return str;
}

void free_str(char *str)
{
    free(str);
}
