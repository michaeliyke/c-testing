#ifndef VALS
#define VALS 1
#define ROWS 2
#define COLS 3
/* ROWS: 10, COLS: 12*/
#include <stdlib.h>
#include <stdio.h>

void print_matrix(void);
void print_matrix_sheet(void);
void make_matrix(int rows, int cols, int *matrix);
int array_arith(int row, int cols, int col);
void sum_rows_n_cols(void);
void sum_2_matices(void);
void print_matrix_x(int rows, int cols, int *matrix);
void matrix_multiplication(void);
int dot_multiply(int *array1, int *array2, int size);
void matrix_mul(void);

#endif
