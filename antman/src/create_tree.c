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

    return leaf_list;
}

// list_t *malist = initialisation();
// remplir_list(list, size, malist);
// afficherlist(malist);
// return 0;
