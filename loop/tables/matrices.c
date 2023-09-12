#include "matrices.h"

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
	matrix_mul();
	return (0);
}

/**
 * sum_2_matices - print the sum of two matrices
 *
 * Return: void
 */
void sum_2_matices(void)
{
	int a[ROWS][COLS];
	int b[ROWS][COLS];
	int c[ROWS][COLS];
	int row, col;

	make_matrix(ROWS, COLS, (int *)a);
	make_matrix(ROWS, COLS, (int *)b);
	make_matrix(ROWS, COLS, (int *)c);
	for (row = 0; row < ROWS; row++)
		for (col = 0; col < COLS; col++)
			c[row][col] = a[row][col] + b[row][col];

	print_matrix_x(ROWS, COLS, (int *)a);
	putchar('\n');
	print_matrix_x(ROWS, COLS, (int *)c);
}

/**
 * print_matrix_x - print a matrix identified by rows and cols
 * @rows: rows
 * @cols: cols
 * @matrix: the matrix to print
 *
 * Return: void
 */
void print_matrix_x(int rows, int cols, int *matrix)
{
	int row, col;

	for (row = 0; row < rows; row++)
	{
		for (col = 0; col < cols; col++)
		{
			if (col != 0)
				putchar(' ');
			printf("%3d", matrix[array_arith(row, cols, col)]);
		}
		putchar('\n');
	}
	putchar('\n');
}

/**
 * matrix_multiplication - multiplies two
 *
 * Return: void
 * A: N*M
 * B: M*P
 * C: N*P
 * Ensures that A->M==B->M
 * That means that the column of A must be the same as the row of B
 * Then the resulting matrix will be row of A * the column of B
 */
void matrix_multiplication(void)
{
	int A[2][3] = {
	    {1, 2, 3},
	    {4, 5, 6},
	},
	    B[3][2] = {
		{7, 8},
		{9, 10},
		{11, 12},
	    },
	    C[2][2] = {{0}};
	int A_rows = 2, B_cols = 2, common = 3;
	int i, j, k;

	for (i = 0; i < A_rows; i++)
		for (j = 0; j < B_cols; j++)
			for (k = 0; k < common; k++)
				C[i][j] += A[i][k] * B[k][j];

	print_matrix_x(2, 3, (int *)A);
	print_matrix_x(3, 2, (int *)B);
	print_matrix_x(2, 2, (int *)C);
}

/**
 * dot_multiply - multiplies matching members and then sum up
 * @array1: first set of integers
 * @array2: second set of integers
 * @size: size of both arrays
 *
 * Return: the sum of the multiplication
 * DOT MULTIPLICATION
 * In dot multiplication, two sets are multiplied by their matching members
 * array1[0] is multiplied by array2[0]
 * array1[1] is multiplied by array2[1]
 * array1[2] is multiplied by array2[2]
 * and so on
 * After all matching members have been multipied, each of the results summed
 * up to a value. This final value is what the function returns
 */
int dot_multiply(int *array1, int *array2, int size)
{
	/**
	 * Since arrays 1 and 2 are of equal size, one iteration is enough
	 * This is because each iteration gives us matching members of both
	 * arrays.
	 */
	int i, sum = 0;

	for (i = 0; i < size; i++)
		sum += array1[i] * array2[i];
	return (sum);
}
