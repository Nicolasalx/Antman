/*
** EPITECH PROJECT, 2023
** def_algo
** File description:
** def_algo
*/

#include "antman.h"
#include "my_string.h"

int total_occurence(file_info_t *file_data)
{
    int compteur = 0;
    for (int x = 0; x < file_data->nb_diff_char; ++x) {
        compteur += file_data->occur_char[x];
    }
    return compteur;
}

int file_def(file_info_t *file_data)
{
    int somme_occurence = total_occurence(file_data);
    if (somme_occurence > file_data->nb_diff_char) {
        return BIG_FILE;
    }
    return SMALL_FILE;
}
