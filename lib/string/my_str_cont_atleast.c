/*
** EPITECH PROJECT, 2022
** my_str_cont_atleast
** File description:
** my_str_cont_atleast
*/

#include "my_string.h"

int my_str_cont_atleast(char *str, char *characters)
{
    int size_characters = my_strlen(characters);
    for (int i = 0; i < size_characters; ++i) {
        if (count_occur(str, characters[i]) < 1) {
            return 0;
        }
    }
    return 1;
}
