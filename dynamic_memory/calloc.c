#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N;
	printf("Enter the size of Array\n: ");
	scanf("%d", &N);

	/* calloc initializes with zero but malloc does not */
	int *A = calloc(N, sizeof(*A));

	for (int i = 0; i < N; i++)
	{
		printf("%d ", A[i]);
	}
}