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

    Matrix* math_createMatrix(int rows, int cols);
    void  math_delMatrix(Matrix* m);

    real  math_get(const Matrix* m, int row, int col);
    void  math_set(Matrix* m, int row, int col, real val);

    Matrix*  math_add(const Matrix* a, const Matrix* b);
    Matrix*  math_sub(const Matrix* a, const Matrix* b);
    Matrix*  math_multiply(const Matrix* a, const Matrix* b);

    void  math_print(const Matrix* m);
    void  math_matrix_input(Matrix* m);

#ifdef __cplusplus
}
#endif