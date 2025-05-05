#include "find_top.h"

int tree_height(struct Leaf *node) {
    if (node == NULL) return 0;
    int left_height = tree_height(node->left);
    int right_height = tree_height(node->right);
    return 1 + (left_height > right_height ? left_height : right_height);
}

void count_nodes_on_level(struct Leaf *node, int current_level, int target_level, LevelStats *stats) {
    if (node == NULL) return;

    if (current_level == target_level) {
        if (node->left != NULL || node->right != NULL) {
            stats->internal_nodes++; 
        } else {
            stats->leaves++;
        }
        return;
    }

    count_nodes_on_level(node->left, current_level + 1, target_level, stats);
    count_nodes_on_level(node->right, current_level + 1, target_level, stats);
}

void print_level_stats(struct Tree *tree) {
    if (tree == NULL || tree->root == NULL) {
        printf("Дерево пусто!\n");
        return;
    }

    int height = tree_height(tree->root);
    printf("Уровень | Внутр. узлы | Листья\n");
    printf("-----------------------------\n");

    for (int level = 0; level < height; level++) {
        LevelStats stats = {0, 0};
        count_nodes_on_level(tree->root, 0, level, &stats);
        printf("%6d  | %10d  | %6d\n", level, stats.internal_nodes, stats.leaves);
    }
}
