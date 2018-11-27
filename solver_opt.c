/*
 * Tema 2 ASC
 * 2018 Spring
 * Catalin Olaru / Vlad Spoiala
 */
#include "utils.h"
#include "complex.h"

double* my_solver(int N, double *A) {

	int i, j, k, size = N << 1;
	double* result = (double*)calloc(2 * N * N, sizeof(double));

	double *pA, *pAt, *pR, *aux;

	for (k = 0; k < N; k++)
	{
		aux = A + (k << 1) + (N - 1) * N * 2;

		for (i = N - 1; i >= 0; i--)
		{
			pA = A + ((i * N + k) << 1);
			pR = result + 2 * i * N + 2 * (N - 1);
			pAt = aux;

			for (j = N - 1; j >= 0; j--)
			{
				if (j < i)
					break;
				complex c1, c2;
				c1.x = *pA;
				c1.y = *(pA + 1);
				c2.x = *pAt;
				c2.y = *(pAt + 1);
				complex sum = multiply(c1, c2);
				*(pR) += sum.x;
				*(pR + 1) += sum.y;
				pAt -= size;
				pR -= 2;
			}
		}
	}

	return result;
}
