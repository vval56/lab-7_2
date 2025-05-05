#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include "header.h"

struct Leaf {
    struct Leaf *left;
    struct Leaf *right;
    struct Leaf *parent;
    int value;
};

struct Tree {
    struct Leaf *root;
    int size;
};

int init_tree(struct Tree *tree);
struct Leaf *create_leaf(int value, struct Leaf *parent);
int Insert(struct Tree *tree, int value);
void print_tree(struct Leaf* node, int level);
void visualize_tree(struct Tree *tree);
int input_tree(struct Tree *tree);
void print_tree_with_highlight(struct Leaf *node, const char *prefix, int is_left, struct Leaf *highlight);
struct Leaf *navigate_tree(struct Leaf *root);
void RecDel(struct Leaf *node);
int delete_leaf(struct Tree *tree);

#endif