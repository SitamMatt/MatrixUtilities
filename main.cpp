#include <iostream>
#include <iomanip>
#include "matrix.h"

using namespace std;

int main() {
    srand(time(0));

    //matrix require those variables
    //int rows = 0, cols = 0, **matrix;
    //matrix = create_matrix(rows,cols);

    //matrix `A`
    int **A, m, n;
    A = create_matrix(m,n);
    //matrix `B`
//    int **B, k, l;
//    B = create_matrix(k,l);

//    int **matrix = merge(A, m, n, B, k, l);
//    if(matrix != nullptr) print_matrix(matrix, m, n);

//    int *sum = sum_diagonal(A, m, n);
//    if(sum != nullptr) cout << *sum;

//    int *min = min_above_diagonal(A,m,n);
//    if(min != nullptr) cout << min[0] << " " << min[1];

//    int *arr = into_array(A, m, n);
//    print_array(arr, m*n);

//    int **transformedZ90Left = transformZ90Left(A,m,n);
//    print_matrix(transformedZ90Left,n,m);

//    int **transformedZ90Right = transformZ90Right(A,m,n);
//    print_matrix(transformedZ90Right,n,m);

//    int **transformedY = transformY(A,m,n);
//    print_matrix(transformedY,m,n);

//    int **transformedX = transformX(A,m,n);
//    print_matrix(transformedX,m,n);

//    int **transposed = transpose(A,m,n);
//    print_matrix(transposed,n,m);

//    int **multiplied = multiply_matrixes(A,m,n,B,k,l);
//    if(multiplied != nullptr) print_matrix(multiplied, m, l);

//    int **tamcos = costam(A,n);
//    print_matrix(tamcos, n,n);

//    int **rotated_quad = rotate90left_in_situ_quad(A, n);
//    print_matrix(rotated_quad, n, n);

//    int **rotated = rotate90left_in_situ_slower(A, m, n);
//    print_matrix(rotated, m, n);

    return 0;
}