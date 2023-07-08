#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N;
	printf("Enter the size of Array\n: ");
	scanf("%d", &N);
	int *A = (int *)malloc(N * sizeof(int));

	for (int i = 0; i < N; i++)
	{
		A[i] = i;
	}

	for (int i = 0; i < N; i++)
	{
		printf("%d ", i);
	}
}