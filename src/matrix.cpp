////////////////////////////////////////////////////////////////////////////////////////////////////
//  Thibault Gounant
//  February 2023
////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>

#include "matrix.h"

using namespace std;
    
////////////////////////////////////////////////////////////////////////////////////////////////////

/*
    The matrix M of dimension n rows * m columns is in the form
    
    a11 a12 a13  .   .  a1m
    a21 a22 a23  .   .   .
    a31 a32 a33  .   .   .
     .   .   .   .   .   .
     .   .   .   .   .   .
    an1  .   .   .   .  anm

    i      =  1   2   3   4   5   6   7   8   9  . . n*m
    M[i-1] = a11 a12 a13 a21 a22 a23 a31 a32 a33 . . anm
    
    M[i * m + j] = aij, i <= n, j <= m
*/

////////////////////////////////////////////////////////////////////////////////////////////////////

double* matrix_addition(double* A, double* B, unsigned int rows_A, unsigned int cols_A, unsigned int rows_B, unsigned int cols_B)
{
    if (rows_A != rows_B || cols_A != cols_B) 
    {
        cout << "Error: Matrices must have the same dimensions to perform addition." << endl;

        return nullptr;
    }

    double* result = new double[rows_A * cols_A];

    for (unsigned int i = 0; i < rows_A; ++i) 
    {
        for (unsigned int j = 0; j < cols_A; ++j) 
        {
            result[i * cols_A + j] = A[i * cols_A + j] + B[i * cols_B + j];
        }
    }

    return result;
}


double* matrix_subtraction(double* A, double* B, unsigned int rows_A, unsigned int cols_A, unsigned int rows_B, unsigned int cols_B)
{
    if (rows_A != rows_B || cols_A != cols_B) 
    {
        cout << "Error: Matrices must have the same dimensions to perform subtraction." << endl;

        return nullptr;
    }

    double* result = new double[rows_A * cols_A];

    for (unsigned int i = 0; i < rows_A; ++i) 
    {
        for (unsigned int j = 0; j < cols_A; ++j) 
        {
            result[i * cols_A + j] = A[i * cols_A + j] - B[i * cols_B + j];
        }
    }

    return result;
}

double* matrix_multiplication(double* A, double* B, unsigned int rows_A, unsigned int cols_A, unsigned int rows_B, unsigned int cols_B)
{
    if (cols_A != rows_B) 
    {
        cout << "Error: The number of columns in matrix A must be equal to the number of rows in matrix B to perform multiplication." << endl;
        
        return nullptr;
    }

    double* result = new double[rows_A * cols_B];

    for (unsigned int i = 0; i < rows_A; ++i) 
    {
        for (unsigned int j = 0; j < cols_B; ++j) 
        {
            double sum = 0.0;
            
            for (unsigned int k = 0; k < cols_A; ++k) 
            {
                sum = sum + A[i * cols_A + k] * B[k * cols_B + j];
            }

            result[i * cols_B + j] = sum;
        }
    }

    return result;
}


double* matrix_inversion(double* A, unsigned int rows, unsigned int cols)
{
    if (rows != cols) 
    {
        cout << "Error: The number of rows must be equal to the number of columns to perform inversion." << endl;
        
        return nullptr;
    }

    // Create a copy of matrix A
    double* copy = new double[rows * cols];
    
    for (unsigned int i = 0; i < rows; ++i) 
    {
        for (unsigned int j = 0; j < cols; ++j) 
        {
            copy[i * cols + j] = A[i * cols + j];
        }
    }

    // Create an identity matrix with the same dimensions as A
    double* identity = new double[rows * cols];
    
    for (unsigned int i = 0; i < rows; ++i) 
    {
        for (unsigned int j = 0; j < cols; ++j) 
        {
            if (i == j) 
            {
                identity[i * cols + j] = 1.0;
            }
            else 
            {
                identity[i * cols + j] = 0.0;
            }
        }
    }

    // Perform Gaussian elimination to transform A into the identity matrix
    for (unsigned int j = 0; j < cols; ++j) 
    {
        // Find the pivot row (the element with the largest absolute value)
        unsigned int pivot = j;

        for (unsigned int i = j + 1; i < rows; ++i) 
        {
            if (abs(copy[i * cols + j]) > abs(copy[pivot * cols + j])) 
            {
                pivot = i;
            }
        }

        // Swap the current row with the pivot row
        if (pivot != j) 
        {
            for (unsigned int k = 0; k < cols; ++k) 
            {
                double temp1 = copy[j * cols + k];
                copy[j * cols + k] = copy[pivot * cols + k];
                copy[pivot * cols + k] = temp1;

                double temp2 = identity[j * cols + k];
                identity[j * cols + k] = identity[pivot * cols + k];
                identity[pivot * cols + k] = temp2;
            }
        }

        // Divide the current row by the pivot element
        double pivot_elem = copy[j * cols + j];

        if (pivot_elem == 0.0) 
        {
            cout << "Error: The determinant is equal to zero so the matrix can not be inverted." << endl;

            delete [] copy;
            delete [] identity;
            
            return nullptr;
        }

        for (unsigned int k = 0; k < cols; ++k) 
        {
            copy[j * cols + k] = copy[j * cols + k] / pivot_elem;

            identity[j * cols + k] = identity[j * cols + k] / pivot_elem;
        }

        // Subtract multiples of the current row from all other rows to zero out their pivot elements
        for (unsigned int i = 0; i < rows; ++i) 
        {
            if (i != j) 
            {
                double multiplier = copy[i * cols + j];

                for (unsigned int k = 0; k < cols; ++k) 
                {
                    copy[i * cols + k] = copy[i * cols + k] - multiplier * copy[j * cols + k];

                    identity[i * cols + k] = identity[i * cols + k] - multiplier * identity[j * cols + k];
                }
            }
        }
    }

    delete [] copy;

    return identity;
}


double* matrix_transpose(double* A, unsigned int rows, unsigned int cols)
{
    double* result = new double[cols * rows];

    for (unsigned int i = 0; i < rows; ++i) 
    {
        for (unsigned int j = 0; j < cols; ++j) 
        {
            result[j * rows + i] = A[i * cols + j];
        }
    }

    return result;
}


void matrix_print(double* A, unsigned int rows, unsigned int cols)
{
    for (unsigned int i = 0; i < rows; ++i) 
    {
        for (unsigned int j = 0; j < cols; ++j) 
        {
            cout << A[i * cols + j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////