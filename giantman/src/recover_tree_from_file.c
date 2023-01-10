/*
** EPITECH PROJECT, 2023
** recover_tree_from_file
** File description:
** recover_tree_from_file
*/

#include "giantman.h"
#include "my_number.h"
#include "my_malloc.h"
#include <stdio.h>

void count_nb_diff_char(file_t *file_data)
{
    file_data->nb_diff_char = 0;
    for (int i = 0; i < (file_data->size_file - 2); ++i) {
        if (file_data->content[i] == '_' && file_data->content[i + 1] == '_') {
            return;
        }
        ++ file_data->nb_diff_char;
        if ((file_data->content[i + 1] == '=' || file_data->content[i + 1] == '<') &&
        (file_data->content[i + 1] != '_' && file_data->content[i + 2] != '_')) {
            ++ i;
        }
    }
}

void recover_tree_from_file(file_t *file_data, tree_t *tree_data)
{
    count_nb_diff_char(file_data);
    file_data->character = malloc_str(file_data->nb_diff_char);
    file_data->occur_char = malloc_array(file_data->nb_diff_char);
    int count_occur_char = 0;
    int index = 0;
    for (int i = 0; i < (file_data->size_file - 2); ++i) {
        if (file_data->content[i] == '_' && file_data->content[i + 1] == '_') {
            tree_data->nb_bit_to_skip = my_get_nb(&file_data->content[i + 2]);
            tree_data->begining_encoded_file = i + 3;
            return;
        }
        file_data->character[index] = file_data->content[i];
        file_data->occur_char[index] = count_occur_char;
        ++ index;
        if ((file_data->content[i + 1] == '=' || file_data->content[i + 1] == '<') &&
            (file_data->content[i + 1] != '_' && file_data->content[i + 2] != '_')) {
            ++ i;
        }
        if (file_data->content[i] == '<') {
            ++ count_occur_char;
        }
    }
}
