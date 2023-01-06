/*
** EPITECH PROJECT, 2023
** encode_file_with_tree
** File description:
** encode_file_with_tree
*/

#include "antman.h"
#include "my_malloc.h"
#include "my_string.h"
#include <stdlib.h>

int get_index_char(char c, char **leaf_path)
{
    for (int i = 0; leaf_path[i] != NULL; ++i) {
        if (c == leaf_path[i][0]) {
            return i;
        }
    }
    return 0;
}

int count_size_new_content_rep(file_info_t *file_data, char **leaf_path)
{
    int count = 0;

    for (int i = 0; file_data->content[i] != '\0'; ++i) {
        int index_char = get_index_char(file_data->content[i], leaf_path);
        for (int j = 1; leaf_path[index_char][j] != '\0'; ++j) {
            ++ count;
        }
    }
    return count;
}

char *change_file_content_rep(file_info_t *file_data, char **leaf_path)
{
    char *new_file_rep =
    malloc_str(count_size_new_content_rep(file_data, leaf_path));
    int index = 0;

    for (int i = 0; file_data->content[i] != '\0'; ++i) {
        int index_char = get_index_char(file_data->content[i], leaf_path);
        for (int j = 1; leaf_path[index_char][j] != '\0'; ++j) {
            new_file_rep[index] = leaf_path[index_char][j];
            ++ index;
        }
    }
    return new_file_rep;
}
