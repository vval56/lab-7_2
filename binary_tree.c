#include "binary_tree.h"

void input_tree(QUEUE *queue) {
    int i = 0;
    char *line = NULL;
    size_t len = 0;

    init_queue(queue);

    puts("Введите целые числа (пустая строчка для завершения)");
    do {
        int number = 0;

        printf("Значение №%d: ", i + 1);
        
        if (getline(&line, &len, stdin) == -1) {
            puts("Ошибка ввода");
            free(line);
            return;
        }

        if (empty_line(line)) {
            if (i == 0) {
                puts("Очередь пуста, введите пожалуйста значение");
                continue;
            }
            break;
        }

        if (check_int(&number, line)) {
            add_element_queue(queue, number);
            i++;
        }

    } while (1);

    free(line);
    queue->size = i;
}

int find_and_remove_min(QUEUE *queue) {
    if (queue == NULL || queue->top == NULL) {
        return -1;
    }

    Node *current = queue->top;
    Node *min_node = current;
    int min = current->data;

    while (current != NULL) {
        if (current->data < min) {
            min = current->data;
            min_node = current;
        }
        current = current->next;
    }

    int temp = queue->top->data;
    queue->top->data = min_node->data;
    min_node->data = temp;

    return delete_element_queue(queue);
}

NODE_TREE *create_node_tree(int value) {
    NODE_TREE *new_node = (NODE_TREE*)malloc(sizeof(NODE_TREE));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->data = value;
    new_node->left = new_node->right = NULL;
    return new_node;
}

NODE_TREE *insert_node_tree(NODE_TREE *tree, int value) {
    if (tree == NULL) {
        return create_node_tree(value);
    }

    if (value < tree->data) {
        tree->left = insert_node_tree(tree->left, value);
    } else if (value > tree->data) {
        tree->right = insert_node_tree(tree->right, value);
    }

    return tree;
}

void create_tree(NODE_TREE **tree, QUEUE *queue) {
    input_tree(queue);

    if (queue->size < 1) {
        puts("Слишком мало введенных данных");
        return;
    }

    while (!is_empty_queue(queue)) {
        *tree = insert_node_tree(*tree, find_and_remove_min(queue));
    }
}

void delete_tree(NODE_TREE *tree) {
    if (tree != NULL) {
        delete_tree(tree->left);
        delete_tree(tree->right);
        free(tree);
    }
}

int tree_height(NODE_TREE* node) {
    if (node == NULL) return 0;
    int left_height = tree_height(node->left);
    int right_height = tree_height(node->right);
    return (left_height > right_height) ? left_height + 1 : right_height + 1;
}
