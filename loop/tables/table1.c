#ifndef VALS
#define VALS 1
#define ROWS 15
#define COLS 30
#include <stdlib.h>
#include <stdio.h>
#endif

void print_matrix(void);
void make_matrix(int rows, int cols, int *matrix);
int array_arith(int row, int cols, int col);

/**
 * main - entry point
 * @argc: argc
 * @argv: argv
 *
 * Return: always 0
 */
int main(int argc, char *argv[])
{

	(void)argc;
	(void)argv;

	print_matrix();
	return (0);
}

/**
 * print_matrix - prints an iteger matrix
 *
 * Return: void
 */
void print_matrix(void)
{
	int row, col;
	int matrix[ROWS][COLS];

	make_matrix(ROWS, COLS, (int *)matrix);
	for (row = 0; row < ROWS; row++)
	{
		for (col = 0; col < COLS; col++)
		{
			if (col != 0)
				putchar(' ');
			printf("%01d", matrix[row][col]);
		}
		putchar('\n');
	}
}

/**
 * make_matrix - makes an inter matrix with dimension rows*cols
 * @rows: height of the matrix
 * @cols: width of the matrix
 *
 * @matrix: memory address of size >= rows*cols*sizeof(int)
 */
void make_matrix(int rows, int cols, int *matrix)
{
	int row, col;

	for (row = 0; row < rows; row++)
		for (col = 0; col < cols; col++)
			matrix[array_arith(row, cols, col)] = row % 10;
}

/**
 * array_arith - array arithmatic for storing item on an array
 * @row: row number
 * @col: col number
 * @cols: total number of cols
 *
 * Return: the accurate location to store an item in array
 * Of course, this is more useful in the context of a multi-dimensional array
 * With this function, you won't need the arr[row][col] notaton for refering
 * to the said location. You only need a array[arr_arith()] to get it right
 */
int array_arith(int row, int cols, int col)
{
	return ((row * cols) + col);
}
