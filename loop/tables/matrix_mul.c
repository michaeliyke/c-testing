#include "matrices.h"

/**
 * matrix_mul - Alrogithm to multiply two matrices
 *
 * Return: void
 *
 * APPLICABLE RULES
 * ----------------
 * a[N][M], b[M][P]
 * a->M must be equal to b->M
 * Then dimension of c will be:
 * c[N][P]
 *
 * i=0 i<N i++
 * --------------
 * Note that each of these rows will go on for all the
 * indivdual columns of the b.
 * So i=0 will run for j-start till j-end
 * Use it to get a hold of the row numbers for a and b
 *
 * j=0 j<P j++
 * -----------
 * j=0 will run for k-start till k-end
 * Ths will help us move horizontally accross b
 * Since k will be changing downwards like this
 * Eg: when j=0; We'll have b[j][k] thus:
 * b[0][0], b[1][0], b[2][0]...
 * and also store store populate c
 *
 * k=0 k<M k++
 * -----------
 * k-end equals width of a, and height of b
 * So k helps us pick values both vertically
 * and horizontally accross a[i][k] row
 * and b[k][j] rows
 * So this is the part that does
 * dot multiplication for us since a[i][k] gives
 * us a row data of a and b[k][j] gives us column
 * data of b
 */
void matrix_mul(void)
{
	int a[3][3] = {{0, 5, 2}, {-1, 1, 0}, {7, 4, 3}};
	int b[3][2] = {{1, 2}, {0, 4}, {3, 5}};
	int c[3][2];
	int i, j, k, N = 3, M = 3, P = 2, sum = 0;

	for (i = 0; i < N; i++)
		for (j = 0; j < P; j++)
		{
			sum = 0;
			for (k = 0; k < M; k++)
				sum += a[i][k] * b[k][j];
			c[i][j] = sum;
		}
	print_matrix_x(N, P, (int *)c);
}
