#include<stdio.h>

typedef struct complex {

	double x;
	double y;

}complex;	// x + i*y
/*
 * Add your unoptimized implementation here
 */
complex multiply(complex a, complex b)
{
	complex r;
	r.x = a.x * b.x - a.y * b.y;
	r.y = a.x * b.y + a.y * b.x;
	return r;
}

complex add(complex a, complex b)
{
	complex r;
	r.x = a.x + b.x;
	r.y = a.y + b.y;
	return r;
}

void print_matrix(int N, double* A)
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%lf + %lf * i\t\t\t", A[2 * (i * N + j)], A[2 * (i * N + j) + 1]);
		}
		printf("\n");
	}
}
