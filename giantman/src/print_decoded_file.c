/*
** EPITECH PROJECT, 2023
** print_decoded_file
** File description:
** print_decoded_file
*/

#include "giantman.h"
#include <unistd.h>
#include <stdlib.h>
#include "my_number.h"
#include <stdio.h>

void print_decoded_file(file_t *file, tree_t *tree)
{
    int nb_bit_to_read = NB_BIT_CHAR;
    node_t *current = tree->head;
    for (int i = tree->begining_encoded_file; i < file->size_file; ++i) {
        if (i >= (file->size_file - 1)) {
            nb_bit_to_read = NB_BIT_CHAR - tree->nb_bit_to_skip;
        }
        for (int j = 0; j < nb_bit_to_read; ++j) {
            unsigned int bit_value = get_bit_value(file->content[i], j);
            if (bit_value == 0) {
                current = current->left;
            } else if (bit_value == 1) {
                current = current->right;
            }
            if (current->type == LEAF) {
                write(1, &current->character, 1);
                current = tree->head;
            }
        }
    }
}
