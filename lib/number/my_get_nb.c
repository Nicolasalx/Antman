/*
** EPITECH PROJECT, 2022
** my_get_nb
** File description:
** my_get_nb
*/

#include "my_string.h"

int is_a_digit(char c)
{
    if (48 <= (int) c && (int) c <= 57) {
        return 1;
    } else {
        return 0;
    }
}

int my_get_nb(const char *str)
{
    int nb = 0;
    int sign = 1;
    int i = 0;
    while (str[i] == ' ') {
        ++i;
    }
    if (str[i] == '-') {
        sign = -1;
        ++i;
    }
    int size_str = my_strlen(str);
    for (; i < size_str; ++i) {
        if (is_a_digit(str[i]) == 1) {
            nb = nb * 10 + (str[i] - '0');
        } else {
            return sign * nb;
        }
    }
    return sign * nb;
}
