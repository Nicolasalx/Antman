/*
** EPITECH PROJECT, 2022
** is_in_str
** File description:
** is_in_str
*/

#include "my_string.h"

int is_in_str(char c, char *str)
{
    int size_str = my_strlen(str);
    for (int i = 0; i < size_str; ++i) {
        if (str[i] == c) {
            return 1;
        }
    }
    return 0;
}
