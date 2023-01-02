/*
** EPITECH PROJECT, 2022
** my_str_only_cont
** File description:
** my_str_only_contains
*/

#include "my_string.h"

int my_str_only_cont(char *str, char *characters)
{
    int size_str = my_strlen(str);
    for (int i = 0; i < size_str; ++i) {
        if (is_in_str(str[i], characters) == 0) {
            return 0;
        }
    }
    return 1;
}
