#include "find_top.h"

// На каждом уровне дерева найти количество внутренних вершин и количество
// листьев.

// Могильный Владислав, 26.04.2025


int main() {

    struct Tree * tree = (struct Tree *)malloc(sizeof(struct Tree));
    init_tree(tree);


    while (1) {

        print_task();

        char c;

        c = choce_task_n_to_m('1', '5');

        switch (c) {
            case '1':
                input_tree(tree);
                break;
            case '2':
                delete_leaf(tree);
                break;
            case '3':
                system("clear");
                visualize_tree(tree);
                system("pause");
                break;
            case '4':
                print_level_stats(tree);
                break;

            case '5':
                exit(1);
        }

    }

    system("pause");
    return 0;
}