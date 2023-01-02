/*
** EPITECH PROJECT, 2022
** my_filelen
** File description:
** my_filelen
*/

#include "my_file.h"

int my_filelen(char *filepath)
{
    struct stat st;
    stat(filepath, &st);
    return st.st_size;
}
