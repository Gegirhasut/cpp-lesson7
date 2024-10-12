#include "c_api.h"
#include "../matrix.h"

struct Matrix: public math::Matrix {
    public:
        Matrix(const struct math::Matrix &m): math::Matrix(m){};
};

Matrix * MATRIXLIB_EXPORT math_createMatrix(int rows, int cols)
{
    return new Matrix(math::Matrix(rows, cols));
}

void MATRIXLIB_EXPORT math_delMatrix(Matrix *m)
{
    delete m;
}

real MATRIXLIB_EXPORT math_get(const Matrix *m, int row, int col)
{
    return m->operator()(row, col);
}

void MATRIXLIB_EXPORT math_set(Matrix *m, int row, int col, real val)
{
    m->operator()(row, col) = val;
}

Matrix * MATRIXLIB_EXPORT math_add(const Matrix *a, const Matrix *b)
{
    return new Matrix(*a + *b);
}

Matrix * MATRIXLIB_EXPORT math_sub(const Matrix *a, const Matrix *b)
{
    return new Matrix(*a - *b);
}

Matrix * MATRIXLIB_EXPORT math_multiply(const Matrix *a, const Matrix *b)
{
    return new Matrix(*a * *b);
}

void MATRIXLIB_EXPORT math_print(const Matrix *m)
{
    m->print();
}

void MATRIXLIB_EXPORT math_matrix_input(Matrix *m)
{
    for (int i = 0; i < m->getRows(); i++) {
        for (int y = 0; y < m->getCols(); y++) {
            std::cout << "At (" << i << "," << y << ") : ";
            std::cin >> m->operator()(i, y);
        }
    }
}
