#pragma once
#include "../export.h"
#include <iostream>

#ifdef MATH_DOUBLE_PREC_DEFINE
typedef double real;
#else
typedef float real;
#endif

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct Matrix Matrix;

    Matrix* MATRIXLIB_EXPORT math_createMatrix(int rows, int cols);
    void MATRIXLIB_EXPORT math_delMatrix(Matrix* m);

    real MATRIXLIB_EXPORT math_get(const Matrix* m, int row, int col);
    void MATRIXLIB_EXPORT math_set(Matrix* m, int row, int col, real val);

    Matrix* MATRIXLIB_EXPORT math_add(const Matrix* a, const Matrix* b);
    Matrix* MATRIXLIB_EXPORT math_sub(const Matrix* a, const Matrix* b);
    Matrix* MATRIXLIB_EXPORT math_multiply(const Matrix* a, const Matrix* b);

    void MATRIXLIB_EXPORT math_print(const Matrix* m);
    void MATRIXLIB_EXPORT math_matrix_input(Matrix* m);

#ifdef __cplusplus
}
#endif