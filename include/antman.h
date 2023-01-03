/*
** EPITECH PROJECT, 2022
** antman
** File description:
** antman
*/

#ifndef ANTMAN
    #define ANTMAN

    #include "my_error.h"

    #define ASCII_RANGE 256
    #define LEAF 0
    #define BRANCH 1

typedef struct file_info_t {
    int nb_diff_char;
    char *character;
    int *occur_char;
} file_info_t;

typedef struct node_t node_t;
struct node_t {
    int type;
    char character;
    int value;
    node_t *parent;
    node_t *left;
    node_t *right;
    node_t *next;
};

typedef struct tree_t tree_t;
struct tree_t {
    node_t *start;
};

typedef struct list_t list_t;
struct list_t {
    node_t *head;
};

int check_arg_validity(int argc, char **argv);
void analyse_file_content(char *filepath, file_info_t *file_content);
void my_sort(int *array, char *str, int size_array);
tree_t *create_tree(file_info_t *file_data);
list_t *create_all_leaf(file_info_t *file_data);
list_t *ini_list(void);
void append_list(list_t *list, char character, int value);
void display_list(list_t *list);

#endif /* !ANTMAN */
