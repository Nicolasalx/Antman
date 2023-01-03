/*
** EPITECH PROJECT, 2023
** my_sort
** File description:
** my_sort
*/

#include "my_number.h"
#include "my_string.h"

int get_min_value(int *array, int size_array, int i)
{
    int index_min_val = i;
    for (; i < size_array; ++i) {
        if (array[i] < array[index_min_val]) {
            index_min_val = i;
        }
    }
    return index_min_val;
}

void my_sort(int *array, char *str, int size_array)
{
    for (int i = 0; i < size_array; ++i) {
        int index_min_val = get_min_value(array, size_array, i);
        if (i != index_min_val) {
            my_swap(&array[i], &array[index_min_val]);
            my_swap_char(&str[i], &str[index_min_val]);
        }
    }
}
