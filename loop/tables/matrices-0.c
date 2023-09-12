#include "matrices.h"
/**
 * sum_rows_n_cols - sum of individual rows and ols of matrix
 *
 * Return: void
 */
void sum_rows_n_cols(void)
{
	int row, col, sum_cols, sum_rows;
	int matrix[ROWS][COLS];

	make_matrix(ROWS, COLS, (int *)matrix);
	for (row = 0; row < ROWS; row++)
	{
		sum_cols = 0, sum_rows = 0;
		for (col = 0; col < COLS; col++)
		{
			sum_rows += matrix[col][row];
			sum_cols += matrix[row][col];
		}
		printf("%d %d\n", sum_rows, sum_cols);
	}
}

/**
 * print_matrix_sheet - prints an iteger matrix
 *
 * Return: void
 */
void print_matrix_sheet(void)
{
	int row, col;
	int matrix_[ROWS][COLS];
	int *matrix = (int *)matrix_; /* Convert 2-D to 1-D array */

	make_matrix(ROWS, COLS, matrix);
	for (row = 0; row < ROWS; row++)
	{
		for (col = 0; col < COLS; col++)
		{
			if (col != 0)
				putchar(' ');
			printf("%01d", matrix[row * COLS + col]);
		}
		putchar('\n');
	}
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
			matrix[array_arith(row, cols, col)] = 1 + (row % 10);
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
