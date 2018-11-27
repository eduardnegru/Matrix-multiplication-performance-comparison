/*
 * Tema 2 ASC
 * 2018 Spring
 * Catalin Olaru / Vlad Spoiala
 */
#include "utils.h"
#include "complex.h"

double* my_solver(int N, double *A)
{
	int i, j, k;
	double* result = (double*)calloc(2 * N * N, sizeof(double));

	for (k = 0; k < N; k++)
	{
		for (j = 0; j < N; j++)
		{
			for (i = 0; i < N; i++)
			{
				if (i > j)
					break;

				complex c1, c2;
				c1.x = A[2 * (i * N + k)];
				c1.y = A[2 * (i * N + k) + 1];
				c2.x = A[2 * (j * N + k)];
				c2.y = A[2 * (j * N + k) + 1];
				complex sum = multiply(c1, c2);
				result[2 * (i * N + j)] += sum.x;
				result[2 * (i * N + j) + 1] += sum.y;
			}
		}
	}

	return result;
}
