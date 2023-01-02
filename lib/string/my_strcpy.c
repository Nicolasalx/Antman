/*
** EPITECH PROJECT, 2022
** my_strcpy
** File description:
** my_strcpy
*/

#include "my_string.h"

void my_strcpy(char *dest, char *src)
{
    int i;
    int size_src = my_strlen(src);
    for (i = 0; i < size_src; ++i) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
}
