#include "queue.h"

#define INT_MAX 32767
#define INT_MIN -32768

int check_int(int *number, char *line) {
    if (line == NULL || line[0] == '\n') {
        return 0;
    }

    int i = 0, sign = 1;
    *number = 0;

    if (line[i] == '-') {
        sign = -1;
        i++;
    }

    while (line[i] != '\0' && line[i] != '\n') {
        if (line[i] < '0' && line[i] > '9') {
            puts("Неверный ввод: допускаются только цифры");
            return 0;
        }
        *number = (*number * 10) + (line[i] - '0');
        i++;
    }

    if (*number > INT_MAX/10 || (*number == INT_MAX/10 && (line[i]-'0') > INT_MAX%10)) {
        puts("Превышено максимальное значение int");
        return 0;
    }

    *number *= sign;
    return 1;
}

int empty_line(char *line) {
    return (line == NULL || line[0] == '\n');
}

void init_queue(QUEUE * queue){
    queue->top = queue->end = NULL;
    queue->size = 0;
}

int is_empty_queue(QUEUE * queue){
    return queue->size == 0;
}

void add_element_queue(QUEUE *queue, int value) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        perror("Ошибка выделения памяти");
        exit(EXIT_FAILURE);
    }
    
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = queue->end;

    if (is_empty_queue(queue)) {
        queue->top = new_node;
    } else {
        queue->end->next = new_node;
    }
    
    queue->end = new_node;
    queue->size++;
}

int peek(QUEUE * queue) {
    if (is_empty_queue(queue)) {
        printf("Очередь пуста!\n");
        return -1;
    }
    return queue->top->data;
}

int delete_element_queue(QUEUE * queue){
    if(is_empty_queue(queue)){
        puts("пустая очередь. Невозможно удалить");
        return -1;
    }

    int value = queue->top->data;

    queue->top = queue->top->next;

    if(queue->top == NULL){
        queue->end = NULL;
    }
    else{
        queue->top->prev = NULL;
    }

    queue->size--;

    return value;
}
