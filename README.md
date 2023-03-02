# Matrix-Operations

5 standards matrix operations according to their overall conception and time complexity.

The matrix is represented with one dimensional array for better memory efficiency.

## Addition

The idea is to iterate over the elements of the two input matrices and add their corresponding elements together in the output matrix.

The matrices must have the same dimensions (n rows, m columns).

So the running time will be O(n*m) !

## Subtraction

The idea is to iterate over the elements of the two input matrices and subtract their corresponding elements together in the output matrix.

The matrices must have the same dimensions (n rows, m columns).

So the running time will be O(n*m) !

## Multiplication

The idea is to iterate over the elements of the two input matrices such that at the ith row of the first matrix and the jth column of the second matrix, we multiply the corresponding elements together and then sum the products in the output matrix.

The first matrix must have the same number of columns as the second matrix has rows (n rows, m columns and m rows, p columns).

So the running time will be O(n*m\*p) !

## Inversion

The idea is to use Gaussian elimination with partial pivoting, the row with the largest absolute value of the pivot element is chosen as the pivot row instead of the current row, to avoid division by very small or zero pivot elements.

The (square) matrix has n rows and n columns.

So the running time will be O(n^3) !

## Transposition

The idea is to iterate over the elements of the input matrix and swap their rows and columns indices in the output matrix.

The matrix has n rows and m columns.

So the running time will be O(n*m) !
