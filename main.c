#include "find_top.h"
#include "binary_tree.h"
#include "queue.h"

// На каждом уровне дерева найти количество внутренних вершин и количество
// листьев.

// Могильный Владислав, 26.04.2025


void show_menu() {
    puts("\nВыберите задание для выполнения:");
    puts("1. Ввести дерево");
    puts("2. Вывести дерево");
    puts("3. Вывести информацию о каждом уровне дерева");
    puts("0. Выход");
    puts("Ваш выбор: ");
}

int main(){
    int choice;
    char *line = NULL;
    size_t len = 0;
    QUEUE queue;
    NODE_TREE * tree;

    while (1) {
        show_menu();

        if (getline(&line, &len, stdin) == -1) {
            puts("Ошибка ввода");
            free(line);
            return 1;
        }

        if (!check_int(&choice, line)) {
            printf("Неверный ввод! Введите число.\n");
            continue;
        }

        switch(choice) {
            case 0:
                free(line);
                puts("Программа завершена.");
                return 0;
            case 1:
                create_tree(&tree, &queue);
                break;
            case 2:
                print_tree(tree);
                break;
            case 3:
                count_by_levels(tree);
                break;
            default:
                printf("Неверный выбор! Допустимые значения: 0-3\n");
        }
    }

    free(line);
    return 0;
}
