#ifndef TREE_H 
#define TREE_H

#include "node.h"

struct binary_search_tree {

        struct Node *head;

        int (*compare)(void *data_one, void *data_two);
        void *(*search)(struct binary_search_tree *tree, void *data);
        void (*insert)(struct binary_search_tree *tree, void *data,unsigned long data_size);
};

struct binary_search_tree binary_search_tree_constructor(int (*compare)(void *data_one, void *data_two));
void binary_search_tree_destructor(struct binary_search_tree binary_search_tree);

int binary_search_tree_int_compare(void *data_one, void *data_two);
int binary_search_tree_float_compare(void *data_one, void *data_two);
int binary_search_tree_char_compare(void *data_one, void *data_two);
int binary_search_tree_str_compare(void *data_one, void *data_two);

#endif // !DEBUG
