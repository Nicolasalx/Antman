/*
** EPITECH PROJECT, 2022
** my_nb_to_str
** File description:
** my_nb_to_str
*/

#include "my_string.h"
#include "my_number.h"

char *my_nb_to_str(int nb)
{
    static char str[12];
    ini_str_to_zero(str, 12);

    if (nb == -2147483648) {
        my_strcpy(str, "-2147483648");
        return str;
    }
    if (nb == 0) {
        my_strcpy(str, "0");
        return str;
    }
    if (nb < 0) {
        str[0] = '-';
        nb = -nb;
    }
    for (int i = count_nb_digit(nb) - 1; nb > 0; --i) {
        str[i] = (nb % 10) + '0';
        nb /= 10;
    }
    return str;
}
