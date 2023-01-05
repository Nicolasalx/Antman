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

// Error Case
int check_arg_validity(int argc, char **argv);
void analyse_file_content(char *filepath, file_info_t *file_content);

// Linked list and tree
void my_sort(int *array, char *str, int size_array);
node_t *create_all_leaf(file_info_t *file_data);
node_t *create_tree(file_info_t *file_data);
node_t *ini_list(void);
void append_node(node_t **head, char character, int value, int type);
void insert_node(node_t **head, node_t *node, int index);
node_t *remove_node(node_t **head, node_t *node);

// Define algo
int total_occurence(file_info_t *file_data);
int file_def(file_info_t *file_data);
void def_algo(file_info_t *file_data);

#endif /* !ANTMAN */
