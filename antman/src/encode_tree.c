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

void encode_tree(char **leaf_path)
{
    for (int i = 0; leaf_path[i] != NULL; ++i) {
        write(1, &leaf_path[i][0], 1);
        for (int j = 1; leaf_path[i][j] != '\0'; ++j) {
            write(1, &leaf_path[i][j], 1);
        }
        my_putstr("|");
    }
    my_putstr(ENCODED_END_TREE);
}
