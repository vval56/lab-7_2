#ifndef FIND_TOP_H
#define FIND_TOP_H

#include "binary_tree.h"

typedef struct LEVEL_INFO{
    int leaves;
    int internal_nodes;
}LEVEL_INFO;

void count_nodes_on_level(NODE_TREE* node, int level, LEVEL_INFO* counts);
void count_by_levels(NODE_TREE* root);

#endif