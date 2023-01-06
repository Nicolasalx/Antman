/*
** EPITECH PROJECT, 2022
** my_malloc
** File description:
** my_malloc
*/

#ifndef MY_MALLOC
    #define MY_MALLOC

char **malloc_board(int nb_line, int size_line);
void free_board(char **board, int nb_line);

char *malloc_str(int size_str);
void free_str(char *str);

char **my_str_to_board(char *str, int nb_line, int *lines_size);

int *malloc_array(int size_array);
void free_array(int *array);

char **my_str_to_word(char *str, char *delimiter, int nb_word, int *size_word);
char **malloc_adv_board(int nb_line, int *lines_size);

#endif /* !MY_MALLOC */
