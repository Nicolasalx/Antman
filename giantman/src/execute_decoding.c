/*
** EPITECH PROJECT, 2023
** execute_decoding
** File description:
** execute_decoding
*/

#include "giantman.h"
#include "my_malloc.h"
#include "my_string.h"

void execute_decoding(file_t *file_data, tree_t *tree_data)
{
    if (file_data->encoding_algo == ALGO_SMALL_FILE) {
        my_putstr(file_data->content);
    } else {
        recover_tree_from_file(file_data, tree_data);
        recreate_tree(file_data, tree_data);
        print_decoded_file(file_data, tree_data);
        free_tree_data(tree_data);
        free_str(file_data->character);
        free_array(file_data->occur_char);
    }
}
