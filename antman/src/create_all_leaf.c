/*
** EPITECH PROJECT, 2023
** create_all_leaf
** File description:
** create_all_leaf
*/

#include "antman.h"

list_t *create_all_leaf(file_info_t *file_data)
{
    list_t *leaf_list = ini_list();
    for (int i = 0; i < file_data->nb_diff_char; ++i) {
        append_list(leaf_list, file_data->character[i],
        file_data->occur_char[i]);
    }
    return leaf_list;
}
