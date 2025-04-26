#include "find_top.h"

void count_nodes_on_level(NODE_TREE* node, int level, LEVEL_INFO* counts) {
    if (node == NULL) return;
    
    if (level == 1) {
        if (node->left != NULL || node->right != NULL) {
            counts->internal_nodes++;
        } else {
            counts->leaves++;
        }
    } else {
        count_nodes_on_level(node->left, level - 1, counts);
        count_nodes_on_level(node->right, level - 1, counts);
    }
}

void count_by_levels(NODE_TREE* root) {
    if (root == NULL) {
        printf("Дерево пустое\n");
        return;
    }

    int height = tree_height(root);
    printf("Уровней в дереве: %d\n", height);

    for (int level = 1; level <= height; level++) {
        LEVEL_INFO counts = {0, 0};
        count_nodes_on_level(root, level, &counts);
        
        printf("Уровень %d: ", level);
        printf("Внутренние вершины = %d, ", counts.internal_nodes);
        printf("Листья = %d\n", counts.leaves);
    }
}