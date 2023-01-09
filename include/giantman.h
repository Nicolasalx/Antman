/*
** EPITECH PROJECT, 2022
** giantman
** File description:
** giantman
*/

#ifndef GIANTMAN
    #define GIANTMAN

    #include "my_error.h"

    #define IS_EMPTY 0
    #define IS_NOT_EMPTY 1

    #define ALGO_SMALL_FILE 0
    #define ALGO_BIG_FILE 1

    #define GET_CHAR 0
    #define GET_CHAR_PATH 1

    #define LEAF 0
    #define BRANCH 1

    #define NB_BIT_CHAR 8

typedef struct file_t {
    char *content;
    long int size_file;
    int encoding_algo;
} file_t;

typedef struct node_t node_t;
struct node_t {
    char character;
    node_t *left;
    node_t *right;
};

typedef struct tree_t {
    node_t *head;
    char **leaf_list;
    int nb_leaf;
    int nb_bit_to_skip;
    int begining_encoded_file;
} tree_t;

int check_arg_validity(int argc, char **argv);
int is_file_not_empty(char *file_path);
void analyze_file_content(char *filepath, file_t *file_data);
void execute_decoding(file_t *file_date, tree_t *tree_data);
void recover_tree_from_file(file_t *file_data, tree_t *tree_data);
void free_all_data(file_t *file_data);
void free_tree_data(tree_t *tree_data);
void recreate_tree(tree_t *tree);
int get_bit_value(unsigned char c, int index_bit);
void print_decoded_file(file_t *file, tree_t *tree);

node_t *create_node(void);

#endif /* !GIANTMAN */
