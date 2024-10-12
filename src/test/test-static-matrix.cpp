#include <iostream>
#include "../matrix.h"

int main () {
    math::Matrix m1(3, 3);
    m1(0, 0) = 1;
    m1(1, 1) = 2;

    math::Matrix m2(3, 3);
    m2(0, 0) = 5;
    m2(1, 1) = 5;

    std::cout << "Matrix m1 is:" << std::endl;
    m1.print();

    std::cout << "Matrix m2 is:" << std::endl;
    m2.print();

    std::cout << "Matrix m1 + m2 is:" << std::endl;
    (m1 + m2).print();

    std::cout << "Matrix m1 * m2 is:" << std::endl;
    std::cout << (m1 * m2) << std::endl;

    return 0;
}