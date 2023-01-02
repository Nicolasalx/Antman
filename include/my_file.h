/*
** EPITECH PROJECT, 2022
** my_file
** File description:
** my_file
*/

#ifndef MY_FILE
    #define MY_FILE

    #include <sys/stat.h>

int open_file(char *filepath);
int my_filelen(char *filepath);
char *my_file_to_str(char *filepath, int file);
int count_nb_line(char *str);
int count_size_first_line(char *str);
int *count_lines_size(char *str, int nb_line);

#endif /* !MY_FILE */
