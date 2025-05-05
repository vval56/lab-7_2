#include "binary_tree.h"

#define GREEN "\033[32m"
#define RESET "\033[0m"

int init_tree(struct Tree *tree) {
    tree->root = NULL;
    tree->size = 0;
    return 0;
}

struct Leaf *create_leaf(int value, struct Leaf *parent) {
    struct Leaf *newLeaf = (struct Leaf *)malloc(sizeof(struct Leaf));
    newLeaf->left = NULL;
    newLeaf->right = NULL;
    newLeaf->value = value;
    newLeaf->parent = parent;
    return newLeaf;
}

int Insert(struct Tree *tree, int value) {
    struct Leaf *currentLeaf = tree->root;
    struct Leaf *parent = NULL;
    int depth = 1;

    if (currentLeaf == NULL) {
        tree->root = create_leaf(value, NULL);
        tree->size = 1;
        return 0;
    }

    while (currentLeaf != NULL) {
        parent = currentLeaf;
        if (value <= currentLeaf->value) {
            currentLeaf = currentLeaf->left;
        } else {
            currentLeaf = currentLeaf->right;
        }
        depth++;
    }

    struct Leaf *newLeaf = create_leaf(value, parent);
    if (value <= parent->value) {
        parent->left = newLeaf;
    } else {
        parent->right = newLeaf;
    }

    if (depth > tree->size) {
        tree->size = depth;
    }

    return 1;
}

void print_tree(struct Leaf* node, int level) {
    if (node == NULL) return;

    // Правая ветвь (выше)
    print_tree(node->right, level + 1);

    // Отступы
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    
    // Ветвь
    if (level > 0) {
        printf(node == node->parent->right ? "/" : "\\");
    }
    
    // Значение
    printf("%d\n", node->value);

    // Левая ветвь (ниже)
    print_tree(node->left, level + 1);
}

void visualize_tree(struct Tree* tree) {
    if (tree->root == NULL) {
        printf("(empty)\n");
        return;
    }
    print_tree(tree->root, 0);
}

int input_tree(struct Tree *tree) {
    while (1) {
        tak_nado();
        int new_value = new_input_metod(INT_MIN + 1, INT_MAX);

        if (new_value == INT_MIN) {
            break;
        } else {
            Insert(tree, new_value);
        }
    }
    return 0;
}

void print_tree_with_highlight(struct Leaf *node, const char *prefix, int is_left, struct Leaf *highlight) {
    if (node == NULL) {
        printf("(Empty tree)\n");
        return;
    }

    if (node->right) {
        char new_prefix[1000];
        snprintf(new_prefix, sizeof(new_prefix), "%s%s", prefix, is_left ? "│   " : "    ");
        print_tree_with_highlight(node->right, new_prefix, 0, highlight);
    }

    if (node == highlight) {
        printf("%s%s" GREEN "%d" RESET "\n", prefix, is_left ? "\\ " : "/", node->value);
    } else {
        printf("%s%s%d\n", prefix, is_left ? "\\" : "/ ", node->value);
    }

    if (node->left) {
        char new_prefix[1000];
        snprintf(new_prefix, sizeof(new_prefix), "%s%s", prefix, is_left ? "    " : "│   ");
        print_tree_with_highlight(node->left, new_prefix, 1, highlight);
    }
}

struct Leaf *navigate_tree(struct Leaf *root) {
    if (root == NULL) return NULL;

    struct Leaf *current = root;
    int ch;

    while (1) {
        system("clear");
        print_tree_with_highlight(root, "", 0, current);

        ch = my_getch();

        if (ch == 'l' && current->left) {
            current = current->left;
        } else if (ch == 'r' && current->right) {
            current = current->right;
        } else if (ch == 'u' && current->parent) {
            current = current->parent;
        } else if (ch == 27) { 
            return NULL;
        } else if (ch == '\n') { 
            return current;
        }
    }
}

void RecDel(struct Leaf *node) {
    if (node == NULL) return;

    RecDel(node->left);
    RecDel(node->right);

    if (node->parent == NULL) {
        node = NULL;
        return;
    }
    if (node == node->parent->left) {
        node->parent->left = NULL;
    }
    if (node == node->parent->right) {
        node->parent->right = NULL;
    }
    free(node);
}

int delete_leaf(struct Tree *tree) {
    struct Leaf *curr = navigate_tree(tree->root);

    if (curr == NULL) {
        return -1;
    }

    if (curr == tree->root) {
        RecDel(curr->left);
        RecDel(curr->right);
        tree->root = NULL;
        return 1;
    }

    RecDel(curr);
    return 0;
}