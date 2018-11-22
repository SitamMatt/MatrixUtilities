//
// Created by matt on 12.11.18.
//

#ifndef MACIERZE_MATRIX_H
#define MACIERZE_MATRIX_H

int **create_matrix(int &rows, int &cols);

void print_matrix(int** matrix, int m, int n);

int **merge(int **A, int n, int m, int **B, int k, int l);

int *sum_diagonal(int **A, int m, int n);

int *min_above_diagonal(int **A, int m, int n);

int *into_array(int **A, int m, int n);

void print_array(int tab[], int n);

int **multiply_matrixes(int **A, int m, int n, int **B, int k, int l);

// matrix transformations
int **transformZ90Left(int **A, int m, int n);

int **transformZ90Right(int **A, int m, int n);

int **transformY(int **A, int m, int n);

int **transformX(int **A, int m, int n);

int **transpose(int **A, int m, int n);

int **rotate90left_in_situ_quad(int **A, int n);

int **rotate90left_in_situ_slower(int **A, int m, int n);

#endif //MACIERZE_MATRIX_H
