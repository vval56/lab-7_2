#ifndef FIND_TOP_H
#define FIND_TOP_H

#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int internal_nodes; 
    int leaves;         
} LevelStats;

int tree_height(struct Leaf *node);
void count_nodes_on_level(struct Leaf *node, int current_level, int target_level, LevelStats *stats);
void print_level_stats(struct Tree *tree);

#endif