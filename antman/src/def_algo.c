#include "antman.h"

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
    int find_file = 0;
    int somme_occurence = total_occurence(file_data);
    if (somme_occurence > file_data->nb_diff_char) {
        find_file = 1;
    }
    return find_file;
}

void def_algo(file_info_t *file_data)
{
    if (file_def(file_data) == 0)
        my_putstr("Fichier petit");

    if (file_def(file_data) == 1) {
        node_t *head_tree = create_tree(file_data);
        my_putstr("Fichier grand");
    }
}
