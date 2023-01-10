/*
** EPITECH PROJECT, 2023
** encode_tree
** File description:
** encode_tree
*/

#include "antman.h"
#include "my_string.h"
#include "my_number.h"
#include <stdlib.h>
#include <unistd.h>

void encode_tree(file_info_t *file_data)
{
    for (int i = 0; i < file_data->nb_diff_char; ++i) {
        write(1, &file_data->character[i], 1);
        my_putstr(my_nb_to_str(file_data->occur_char[i]));
        my_putstr("|");
    }
    my_putstr(ENCODED_END_TREE);
}
