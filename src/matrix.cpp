#include "matrix.h"
#include <iostream>

using namespace math;

int math::Matrix::getRows()
{
    return this->rows_;
}

int math::Matrix::getCols()
{
    return this->cols_;
}

real &Matrix::operator()(int row, int col)
{
    if (row >= rows_ || col >= cols_) {
        std::cerr << "Matrix out of bounds" << std::endl;
        // return 0;
    }
    int pos(0);

    pos = cols_ * row + col;

    return this->mvec_.at(pos);
}

real math::Matrix::operator()(int row, int col) const
{
    if (row >= rows_ || col >= cols_) {
        std::cerr << "Matrix out of bounds" << std::endl;
        // return 0;
    }
    int pos(0);

    pos = cols_ * row + col;

    return this->mvec_.at(pos);
}

void Matrix::print() const
{
    for (int i = 0;i < rows_; i++) {
        for (int y = 0; y < cols_; y++) {
            std::cout << this->mvec_.at(cols_ * i + y) << " ";
        }

        std::cout << std::endl;
    }

    std::cout << "---" << std::endl;
}

std::ostream &math::operator<<(std::ostream &out, const Matrix &m)
{
    for (int i = 0; i < m.rows_; i++) {
        for (int y = 0; y < m.cols_; y++) {
            out << m.mvec_.at(m.cols_ * i + y) << " ";
        }

        out << std::endl;
    }

    out << "---" << std::endl;

    return out;
}

std::istream &math::operator>>(std::istream &in, Matrix &m)
{
    for (int i = 0; i < m.rows_; i++) {
        for (int y = 0; y < m.cols_; y++) {
            std::cout << "At (" << i << "," << y << ") : ";
            in >> m(i, y);
        }
    }
    return in;
}

Matrix math::operator+(const Matrix a, const Matrix b)
{
    if ((a.cols_ != b.cols_) || (a.rows_ != b.rows_)) {
        std::cerr<<"Error: Matrixes has different sizes"<<std::endl;
        return Matrix(0,0);
    }
    
    Matrix m(a.cols_, a.rows_);
    for(int i = 0; i < a.mvec_.size(); i++) {
        m.mvec_.at(i) = a.mvec_.at(i) + b.mvec_.at(i);
    }

    return m;
}

Matrix &math::Matrix::operator+=(const Matrix &b)
{
    if ((this->cols_ != b.cols_) || (this->rows_ != b.rows_)) {
        std::cerr<<"Error: Matrixes has different sizes"<<std::endl;
        return *this;
    }
    
    for(int i = 0; i < this->mvec_.size(); i++) {
        this->mvec_.at(i) += b.mvec_.at(i);
    }

    return *this;
}

Matrix math::operator-(const Matrix a, const Matrix b)
{
    if ((a.cols_ != b.cols_) || (a.rows_ != b.rows_)) {
        std::cerr<<"Error: Matrixes has different sizes"<<std::endl;
        return Matrix(0,0);
    }
    
    Matrix m(a.cols_, a.rows_);
    for(int i = 0; i < a.mvec_.size(); i++) {
        m.mvec_.at(i) = a.mvec_.at(i) - b.mvec_.at(i);
    }

    return m;
}

Matrix &math::Matrix::operator-=(const Matrix &b)
{
    if ((this->cols_ != b.cols_) || (this->rows_ != b.rows_)) {
        std::cerr<<"Error: Matrixes has different sizes"<<std::endl;
        return *this;
    }
    
    for(int i = 0; i < this->mvec_.size(); i++) {
        this->mvec_.at(i) -= b.mvec_.at(i);
    }

    return *this;
}

Matrix math::operator*(const Matrix a, const Matrix b)
{
    if (a.cols_ != b.rows_) {
        std::cerr<<"Error: Matrixes cat't be multiplied"<<std::endl;
        return Matrix(0,0);
    }
    
    Matrix m(a.rows_, b.cols_);
    for(int i = 0; i < m.mvec_.size(); i++) {
        int row = std::floor(i/m.cols_);
        int col = i - row * m.cols_;

        for (int y = 0; y < a.cols_; y++) {
            m.mvec_.at(i) += a(row, y) * b(y, col);
        }
    }

    return m;
}

Matrix &math::Matrix::operator*=(const int val)
{
    for(int i = 0; i < this->mvec_.size(); i++) {
        this->mvec_.at(i) *= val;
    }

    return *this;
}