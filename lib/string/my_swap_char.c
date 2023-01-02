/*
** EPITECH PROJECT, 2022
** my_swap
** File description:
** my_swap
*/

void my_swap_char(char *char_1, char *char_2)
{
    char stock;
    stock = *char_1;
    *char_1 = *char_2;
    *char_2 = stock;
}
