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

    #define SMALL_FILE 0
    #define BIG_FILE 1
    #define CAP_BIG_FILE 8

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

typedef struct tree_data_t {
    node_t *head_tree;
    node_t **leaf_list;
} tree_data_t;


// Error Case
int check_arg_validity(int argc, char **argv);
void analyse_file_content(char *filepath, file_info_t *file_content);

// Linked list and tree
void my_sort(int *array, char *str, int size_array);
void create_all_leaf(file_info_t *file_data, tree_data_t *tree);
void create_tree(file_info_t *file_data, tree_data_t *tree);
void encode_tree(node_t **leaf_list, file_info_t *file_data);
void free_tree(tree_data_t *tree);
node_t *ini_list(void);
void append_node(node_t **head, char character, int value, int type);
void insert_node(node_t **head, node_t *node, int index);
node_t *remove_node(node_t **head, node_t *node);

// Define algo
int def_file_category(file_info_t *file_data);

void free_all_data(file_info_t *file_data);

#endif /* !ANTMAN */
