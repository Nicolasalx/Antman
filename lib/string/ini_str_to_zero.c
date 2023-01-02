/*
** EPITECH PROJECT, 2022
** ini_str_to_zero
** File description:
** ini_str_to_zero
*/

void ini_str_to_zero(char *str, int size_str)
{
    for (int i = 0; i < size_str; ++i) {
        str[i] = '\0';
    }
}
