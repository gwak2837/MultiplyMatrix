#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MultiplyMatrix.h"

int main()
{
	time_t start = 0, end = 0;
	int **matrix1 = NULL, **matrix2 = NULL, **result = NULL;
	int length, max;
	int i;
	int count = 10;

	srand((size_t)time(NULL));

	fputs("Input the width or height of the square matrix : ", stdout);
	scanf("%d", &length);
	getchar();

	fputs("Input the maximum number of the matrix : ", stdout);
	scanf("%d", &max);
	getchar();

	start = clock();
	for (i = 0; i < count; i++)
	{
		matrix1 = createSquareMatrix(matrix1, length, max);
		matrix2 = createSquareMatrix(matrix2, length, max);
		result = multiplySquareMatix(matrix1, length, matrix2, length);
		freeSquareMatrix(matrix1);
		freeSquareMatrix(matrix2);
		freeSquareMatrix(result);
	}
	end = clock();

	printf("Elasped time : %lf sec\n", (double)(end - start) / CLOCKS_PER_SEC);
	system("pause");
	return 0;
}
