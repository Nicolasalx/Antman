/*
** EPITECH PROJECT, 2022
** count_occur
** File description:
** count_occur
*/

#include "my_string.h"

int count_occur(char *str, char c)
{
    int size_str = my_strlen(str);
    int count = 0;
    for (int i = 0; i < size_str; ++i) {
        if (str[i] == c) {
            ++count;
        }
    }
    return count;
}
