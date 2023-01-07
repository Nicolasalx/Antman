/*
** EPITECH PROJECT, 2023
** func_bit_manipulation
** File description:
** func_bit_manipulation
*/

#include "antman.h"

void set_bit_to_zero(unsigned char *c, int index_bit)
{
    *c &= ~(1 << index_bit);
}

void set_bit_to_one(unsigned char *c, int index_bit)
{
    *c |= 1 << index_bit;
}

void set_all_bit_to_zero(unsigned char *c)
{
    *c = 0;
}

int get_bit_value(unsigned char c, int index_bit)
{
    return ((c & (1 << index_bit)) >> index_bit);
}
