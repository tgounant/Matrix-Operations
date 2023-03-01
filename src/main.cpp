////////////////////////////////////////////////////////////////////////////////////////////////////
//  Thibault Gounant
//  February 2023
////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "matrix.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{    
    cout << "A:" << endl;

    double A[3*3] = 
    {
        -1, 0, 1,
        0, 1, 0,
        1, 1, 2
    };

    matrix_print(A,3,3);

    cout << "B:" << endl;

    double B[3*3] = 
    {
        0, 1, 0,
        0, 0, 1,
        1, 0, 0
    };

    matrix_print(B,3,3);


    cout << "Addition:" << endl;

    double* add = matrix_addition(A,B,3,3,3,3);

    matrix_print(add,3,3);


    cout << "Subtraction:" << endl;

    double* sub = matrix_subtraction(A,B,3,3,3,3);

    matrix_print(sub,3,3);


    cout << "Multiplication:" << endl;
    
    double* mul = matrix_multiplication(A,B,3,3,3,3);
    
    matrix_print(mul,3,3);


    cout << "Inversion:" << endl;

    double* inv = matrix_inversion(A,3,3);

    matrix_print(inv,3,3);


    cout << "Transpose:" << endl;

    double* tra = matrix_transpose(A,3,3);

    matrix_print(tra,3,3);


    return EXIT_SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////////////////////////