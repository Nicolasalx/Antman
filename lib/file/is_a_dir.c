/*
** EPITECH PROJECT, 2023
** my_lib
** File description:
** is_a_dir
*/

#include <sys/stat.h>

int is_a_dir(const char *path)
{
    struct stat st;
    stat(path, &st);
    if (S_ISDIR(st.st_mode)) {
        return 1;
    }
    return 0;
}
