/*
** EPITECH PROJECT, 2022
** antman
** File description:
** antman
*/

#ifndef ANTMAN
    #define ANTMAN

    #include "my_error.h"

    #define ASCII_RANGE 4097
    #define ENCODED_END_TREE "__"

    #define IS_EMPTY 0
    #define IS_NOT_EMPTY 1

    #define LEAF 0
    #define BRANCH 1

    #define SMALL_FILE 0
    #define BIG_FILE 1
    #define CAP_BIG_FILE 2

typedef struct file_info_t {
    char *content;
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
int is_file_not_empty(char *file_path);
void analyse_file_content(char *filepath, file_info_t *file_content);

// Linked list and tree
void my_sort(int *array, char *str, int size_array);
void create_all_leaf(file_info_t *file_data, tree_data_t *tree);
void create_tree(file_info_t *file_data, tree_data_t *tree);
void encode_tree(file_info_t *file_data);
int *count_size_path_leaf(file_info_t *file_data, tree_data_t *tree);
char **get_all_leaf_path(file_info_t *file_data, tree_data_t *tree);
char *change_file_content_rep(file_info_t *file_data, char **leaf_path);
void encode_str_to_byte(char *str);
void free_tree_and_leaf(tree_data_t *tree, file_info_t *file_data,
    char **leaf_path, char *new_file_rep);
node_t *ini_list(void);
void append_node(node_t **head, char character, int value, int type);
void insert_node(node_t **head, node_t *node, int index);
node_t *remove_node(node_t **head, node_t *node);

// Define algo
int def_file_category(file_info_t *file_data);

void set_bit_to_zero(unsigned char *c, int index_bit);
void set_bit_to_one(unsigned char *c, int index_bit);
void set_all_bit_to_zero(unsigned char *c);
int get_bit_value(unsigned char c, int index_bit);

void free_all_data(file_info_t *file_data);

void execute_encoding(file_info_t *file_data, tree_data_t *tree);

#endif /* !ANTMAN */
