/*
** EPITECH PROJECT, 2023
** func_bit_manipulation
** File description:
** func_bit_manipulation
*/

#include "antman.h"

void set_bit_to_zero(char *c, int index_bit)
{
    *c &= ~(1 << index_bit);
}

void set_bit_to_one(char *c, int index_bit)
{
    *c |= 1 << 3;
}

void set_all_bit_to_zero(char *c)
{
    *c = 0;
}
