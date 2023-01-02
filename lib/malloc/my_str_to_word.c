/*
** EPITECH PROJECT, 2022
** my_str_to_word
** File description:
** my_str_to_word
*/

#include "my_string.h"
#include "my_malloc.h"
#include <stdlib.h>

char **my_str_to_word(char *str, char *delimiter, int nb_word, int *size_word)
{
    int size_str = my_strlen(str);
    char **words = adv_board(nb_word, size_word);
    int i_index = 0;
    int j_index = 0;
    int end_word = 0;
    for (int i = 0; i < size_str; ++i) {
        if (is_in_str(str[i], delimiter) == 0) {
            words[i_index][j_index] = str[i];
            ++ j_index;
            end_word = 1;
        }
        if (is_in_str(str[i], delimiter) == 1 && end_word == 1) {
            end_word = 0;
            ++ i_index;
            j_index = 0;
        }
    }
    return words;
}
