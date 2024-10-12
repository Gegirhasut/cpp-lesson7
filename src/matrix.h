#pragma once
#include <vector>
#include <iostream>

namespace math {
    typedef double real;
    class Matrix {
        private:
            int cols_;
            int rows_;
            std::vector<real> mvec_;
        public:
            Matrix(){};
            int getRows();
            int getCols();
            Matrix(int rows, int cols) : cols_(cols), rows_(rows), mvec_(std::vector<real>(rows * cols)) {};
            real& operator()(int row, int col);
            real operator()(int row, int col) const;
            friend Matrix operator+(const Matrix a, const Matrix b);
            Matrix& operator+=(const Matrix& b);
            friend Matrix operator-(const Matrix a, const Matrix b);
            Matrix& operator-=(const Matrix& b);
            friend Matrix operator*(const Matrix a, const Matrix b);
            Matrix& operator*=(const int val);
            void print() const;
            friend std::ostream& operator << (std::ostream &out, const Matrix &m);
            friend std::istream& operator >> (std::istream &in, Matrix &m);
    };
}