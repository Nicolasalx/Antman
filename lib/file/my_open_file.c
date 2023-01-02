/*
** EPITECH PROJECT, 2022
** my_open_file
** File description:
** my_open_file
*/

#include <fcntl.h>

int open_file(char *filepath)
{
    return open(filepath, O_RDONLY);
}
