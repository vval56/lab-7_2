#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <termios.h>
#include <unistd.h>
#include <stdbool.h>

int check_int_1(const char *input, int min, int max);
int my_getch();
int new_input_metod(int min, int max);
char choce_task_n_to_m(char n, char m);
void print_task();
void tak_nado();
void tak_nado_1();

#endif