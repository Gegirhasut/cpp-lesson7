/*#include <iostream>
#include "../matrix.h"
#include "../c/c_api.h"*/

#include "../export.h"

struct Matrix;

#ifdef __cplusplus
extern "C"
{
#endif
    typedef double real;
    extern Matrix* math_createMatrix(int , int );
    extern void  math_delMatrix(Matrix* );

    extern void  math_set(Matrix* , int , int , real val);

    extern void  math_print(const Matrix* m);

#ifdef __cplusplus
}
#endif

int main () {
    Matrix* m = math_createMatrix(3, 3);

    math_set(m, 0, 0, 1);
    math_set(m, 1, 1, 1);

    math_print(m);

    math_delMatrix(m);

    return 0;
}