/*
** EPITECH PROJECT, 2022
** array
** File description:
** malloc_an_array
*/

#include <stdlib.h>

int *malloc_array(int size_array)
{
    int i;
    int *array = malloc(sizeof(int) * (size_array));
    for (i = 0; i < size_array; ++i) {
        array[i] = 0;
    }
    return array;
}

void free_array(int *array)
{
    free(array);
}
