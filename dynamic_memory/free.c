#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N;
	printf("Enter the size of Array\n: ");
	scanf("%d", &N);
	int *A = malloc(N * sizeof(*A));

	for (int i = 0; i < N; i++)
	{
		A[i] = i * i;
	}

	for (int i = 0; i < N; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");

	free(A); /* makes memory available for another malloc call */

	/* Confirm data is part of garbage now */

	for (int i = 0; i < N; i++)
	{
		printf("%d ", A[i]);
	}
}