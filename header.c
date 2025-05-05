#include "header.h"

int check_int_1(const char *input, int min, int max) {
    if (input == NULL || *input == '\0') {
        return 0;
    }

    const char *ptr = input;
    int is_negative = 0;

    if (*ptr == '-') {
        if (min >= 0) {
            return 0;
        }
        is_negative = 1;
        ptr++;
    }

    if (*ptr == '\0') {
        return 0;
    }

    long long int result = 0;
    while (*ptr != '\0') {
        if (*ptr < '0' || *ptr > '9') {
            return 0;
        }
        int digit = *ptr - '0';

        result = result * 10 + digit;
        ptr++;
    }

    if (is_negative) {
        result = -result;
    }

    if (result < min || result > max) {
        return 0;
    }

    return 1;
}

int my_getch() {
    struct termios oldt, newt;
    int ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ch = getchar();

    if (ch == 27) {
        ch = getchar(); 
        ch = getchar(); 
        switch (ch) {
            case 'A': ch = 'u'; break; 
            case 'B': ch = 'd'; break; 
            case 'C': ch = 'r'; break; 
            case 'D': ch = 'l'; break; 
        }
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

int new_input_metod(int min, int max) {
    char buffer[256];
    int i = 0;
    int ch;

    while (1) {
        ch = my_getch();

        if (ch == 27) { 
            return INT_MIN;
        }

        if (ch == '\n' || ch == '\r') { 
            buffer[i] = '\0';
            if (check_int_1(buffer, min, max)) {
                long long num;
                sscanf(buffer, "%lld", &num);
                return (int)num;
            } else {
                printf("\nНекорректный ввод. Попробуйте снова: ");
                i = 0;
            }
        } else if (ch == '\b') {
            if (i > 0) {
                printf("\b \b");
                i--;
            }
        } else if ((ch >= '0' && ch <= '9') || (ch == '-' && i == 0)) {
            if (i < 255) {
                buffer[i++] = (char)ch;
                putchar(ch);
            }
        }
    }
}

char choce_task_n_to_m(char n, char m) {
    char c;
    while (1) {
        c = my_getch();
        if (c >= n && c <= m) {
            return c;
        }
    }
}

void print_task() {

    printf("Нажмите:\n");
    printf("1 - для ввода дерева\n");
    printf("2 - для выбора и удаления элемента дерева\n");
    printf("3 - для визуализации дерева\n");
    printf("4 - вывести информацию о узлах\n");
    printf("5 - выход\n\n");
}

void tak_nado() {
    printf("\n\nВведите значение узла (или ESC для завершения): ");
}

void tak_nado_1() {
    printf("\n\nВыбирайте стрелочками, какой узел вы хотите удалить (ESC - выход):");
}
