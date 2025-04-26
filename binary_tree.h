#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include <math.h>
#include <string.h>

typedef struct NODE_TREE {
    int data;
    struct NODE_TREE* left;
    struct NODE_TREE* right;
} NODE_TREE;

void input_tree(QUEUE *queue);
int find_and_remove_min(QUEUE *queue);
NODE_TREE *create_node_tree(int value);
NODE_TREE *insert_node_tree(NODE_TREE *tree, int value);
void create_tree(NODE_TREE **tree, QUEUE *queue);
void delete_tree(NODE_TREE *tree);
int tree_height(NODE_TREE* node);
void fill_output(char** output, NODE_TREE* node, int level, int left, int right);
void print_tree(NODE_TREE* root) ;

#endif