#include "c_api.h"
#include "../matrix.h"

struct Matrix: public math::Matrix {
    public:
        Matrix(const struct math::Matrix &m): math::Matrix(m){};
};

Matrix * math_createMatrix(int rows, int cols)
{
    return new Matrix(math::Matrix(rows, cols));
}

void  math_delMatrix(Matrix *m)
{
    delete m;
}

real  math_get(const Matrix *m, int row, int col)
{
    return m->operator()(row, col);
}

void  math_set(Matrix *m, int row, int col, real val)
{
    m->operator()(row, col) = val;
}

Matrix *  math_add(const Matrix *a, const Matrix *b)
{
    return new Matrix(*a + *b);
}

Matrix *  math_sub(const Matrix *a, const Matrix *b)
{
    return new Matrix(*a - *b);
}

Matrix *  math_multiply(const Matrix *a, const Matrix *b)
{
    return new Matrix(*a * *b);
}

void math_print(const Matrix *m)
{
    m->print();
}

void  math_matrix_input(Matrix *m)
{
    for (int i = 0; i < 3; i++) {
        for (int y = 0; y < 3; y++) {
            std::cout << "At (" << i << "," << y << ") : ";
            std::cin >> m->operator()(i, y);
        }
    }
}
