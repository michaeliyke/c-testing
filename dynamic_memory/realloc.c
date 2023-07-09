#include <stdio.h>
#include <stdlib.h>

void print_ints(int *A, int N);

int main(void)
{
	int N;
	printf("Enter the size of Array\n#: ");
	scanf("%d", &N);

	/* calloc initializes with zero but malloc does not */
	int *A = (int *)calloc(N, sizeof(int));
	print_ints(A, N);

	// Gain extra memory
	N = (N + 5);
	A = (int *)realloc(A, N * sizeof(int));
	print_ints(A, N);

	// Reduce memory
	N = N - 6;
	A = (int *)realloc(A, N * sizeof(int));
	print_ints(A, N);

	// realloc used like malloc
	N = N + 6;
	A = (int *)realloc(NULL, N * sizeof(int));
	print_ints(A, N);

	// realloc used like free
	A = (int *)realloc(A, 0);
	print_ints(A, N);
}

void print_ints(int *A, int N)
{
	printf("\nPrinting %p:\n", A);
	for (int i = 0; i < N; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n:END\n");
}
