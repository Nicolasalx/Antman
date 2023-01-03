/*
** EPITECH PROJECT, 2023
** fill_list
** File description:
** fill_list
*/

#include "antman.h"

tree_t *create_tree(file_info_t *file_data)
{
    list_t *leaf_list = create_all_leaf(file_data);
    display_list(leaf_list);
    return;
}
