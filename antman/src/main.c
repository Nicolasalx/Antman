/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "antman.h"
#include "my_file.h"
#include "my_malloc.h"
#include "my_string.h"

int main(int argc, char **argv)
{
    int file = open_file(argv[1]);
    char *buff = my_file_to_str(argv[1], file);
    my_putstr(buff);
    my_putstr("\n");
    return 0;
}
