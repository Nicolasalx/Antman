/*
** EPITECH PROJECT, 2023
** is_file_not_empty.c
** File description:
** is_file_not_empty
*/

#include "antman.h"
#include "my_file.h"

int is_file_not_empty(char *file_path)
{
    int file = open_file(file_path);
    if (file == -1) {
        return IS_NOT_EMPTY;
    }
    if (my_filelen(file_path) > 0) {
        return IS_NOT_EMPTY;
    }
    return IS_EMPTY;
}
