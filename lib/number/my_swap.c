/*
** EPITECH PROJECT, 2023
** my_swap
** File description:
** my_swap
*/

void my_swap(int *value_a, int *value_b)
{
    int stock;
    stock = *value_a;
    *value_a = *value_b;
    *value_b = stock;
}
