/*
** EPITECH PROJECT, 2022
** randint
** File description:
** randint
*/

#include <stdlib.h>

int rand_int(int min, int max)
{
    return ((rand() % (((max) + 1) - (min))) + (min));
}
