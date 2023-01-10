/*
** EPITECH PROJECT, 2023
** encode_tree
** File description:
** encode_tree
*/

#include "antman.h"
#include "my_string.h"
#include <stdlib.h>
#include <unistd.h>

void encode_tree(file_info_t *file_data)
{
    int i = 0;
    for (; i < (file_data->nb_diff_char - 1); ++i) {
        write(1, &file_data->character[i], 1);
        if (file_data->occur_char[i] == file_data->occur_char[i + 1]) {
            write(1, "=", 1);
        } else {
            write(1, "<", 1);
        }
    }
    write(1, &file_data->character[i], 1);
    my_putstr(ENCODED_END_TREE);
}
