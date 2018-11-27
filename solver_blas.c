/*
 * Tema 2 ASC
 * 2018 Spring
 * Catalin Olaru / Vlad Spoiala
 */
#include "utils.h"
#include "complex.h"
#include "cblas.h"

double* my_solver(int N, double *A) {

        double* result = (double*)calloc(2 * N * N, sizeof(double));

        const enum CBLAS_ORDER Order=CblasRowMajor;
        const enum CBLAS_UPLO Uplo = CblasUpper;
        const enum CBLAS_TRANSPOSE Trans = CblasNoTrans;

        double alpha = 1;
        double beta = 0;

        int s = N;

        cblas_zsyrk(Order, Uplo, Trans, s, s, &alpha, A, s, &beta, result, N);


        return result;

}
~
~