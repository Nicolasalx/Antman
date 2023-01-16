/*
** EPITECH PROJECT, 2022
** my_file_to_str
** File description:
** my_file_to_str
*/

#include "my_file.h"
#include <stdlib.h>
#include <unistd.h>

char *my_file_to_str(char *filepath, int file)
{
    long int size_file = my_filelen(filepath);
    char *buff = malloc(sizeof(char) * (size_file + 1));
    read(file, buff, size_file);
    buff[size_file] = '\0';
    close(file);
    return buff;
}
