/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "antman.h"
#include "my_string.h"

int main(int argc, char **argv)
{
    file_info_t file_data;
    if (check_arg_validity(argc, argv) != 0)
        return 84;

    analyse_file_content(argv[1], &file_data);
    if (error_manager(0) != 0)
        return 84;
    my_sort(file_data.occur_char, file_data.character, file_data.nb_diff_char);

    if (def_file_category(&file_data) == SMALL_FILE) {
        my_putstr("Fichier petit\n");
        // call algo small file
    } else {
        my_putstr("Fichier grand\n");
        node_t *head_tree = create_tree(&file_data);
    }

    free_all_data(&file_data);
    return 0;
}
