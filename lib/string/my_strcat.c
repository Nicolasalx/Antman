/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** my_strcat
*/

#include "my_string.h"

char *my_strcat(char *dest, char *src)
{
    int size_dest = my_strlen(dest);
    int size_src = my_strlen(src);
    int i;
    for (i = 0; i < size_src; ++i) {
        dest[i + size_dest] = src[i];
    }
    dest[i + size_dest] = '\0';
    return dest;
}
