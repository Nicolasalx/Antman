/*
** EPITECH PROJECT, 2022
** my_string
** File description:
** my_string
*/

#ifndef MY_STRING
    #define MY_STRING

void my_putstr(const char *str);
char *my_strcat(char *dest, char *src);
int my_strcmp(char const *str1, char const *str2);
void my_strcpy(char *dest, char *src);
int my_strlen(const char *str);
int is_in_str(char c, char *str);
int my_str_only_cont(char *str, char *characters);
int count_occur(char *str, char c);
int my_str_cont_atleast(char *str, char *characters);
int count_nb_word(char *str, char *delimiter);
int *count_size_word(char *str, char *delimiter, int nb_word);
void ini_str_to_zero(char *str, int size_str);
void my_swap_char(char *char_1, char *char_2);
char *my_revstr(char *str);

#endif /* !MY_STRING */
