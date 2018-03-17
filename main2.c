#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
	time_t startTime = 0, endTime = 0;

	int **matrix1 = NULL;
	int **matrix2 = NULL;
	int **result = NULL;
	int size;
	int i, j, a, b, c;
	int count = 10;

	srand((unsigned int)time(NULL));

	fputs("Input the size of the square matrix : ", stdout);
	scanf("%d", &size);
	getchar();

	startTime = clock();
	for (i = 0; i < count; i++)
	{
		// create matrix1 using dynamic allocation
		matrix1 = (int **)calloc(size, sizeof(int *));
		matrix1[0] = (int *)calloc(size * size, sizeof(int));
		for (j = 1; j < size; j++)
		{
			matrix1[j] = matrix1[j - 1] + size;
		}
		for (i = 0; i < size * size; i++)
		{
			matrix1[0][i] = rand();

		}
		// create matrix2 using dynamic allocation
		matrix2 = (int **)calloc(size, sizeof(int *));
		matrix2[0] = (int *)calloc(size * size, sizeof(int));
		for (j = 1; j < size; j++)
		{
			matrix2[j] = matrix2[j - 1] + size;
		}
		for (i = 0; i < size * size; i++)
		{
			matrix2[0][i] = rand();

		}

		// create result matrix using dynamic allocation
		result = (int **)calloc(size, sizeof(int *));
		result[0] = (int *)calloc(size * size, sizeof(int));
		for (j = 1; j < size; j++)
		{
			result[j] = result[j - 1] + size;
		}
		 
		// multiply two matrix and the result save in the result matrix
		for (a = 0; a < size; a++)
		{
			for (b = 0; b < size; b++)
			{
				for (c = 0; c < size; c++)
					result[a][b] += matrix1[a][c] * matrix2[c][b];
			}
		}

		free(matrix1[0]);
		free(matrix1);
		free(matrix2[0]);
		free(matrix2);
		free(result[0]);
		free(result);
	}
	endTime = clock();

	printf("Average elasped time of the %d x %d matrix operation : %lf sec\n", size, size, ((double)(endTime - startTime) / CLOCKS_PER_SEC) / count);
	system("pause");
}
