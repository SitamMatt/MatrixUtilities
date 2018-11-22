//
// Created by matt on 12.11.18.
//
#include <iostream>
#include <iomanip>
#include "matrix.h"

// utlilites
int *null_msg(char msg[]){
    std:: cout << msg;
    return nullptr;
}

void print_array(int tab[], int n){
    for (int i = 0; i < n; ++i) {
        std::cout << tab[i] << ", ";
    }
}
// matrix tools

int **create_matrix(int &rows, int &cols){
    // wprowadzanie liczby wierszy macierzy `A`
    std::cout << "Wprowadź liczbę wierszy rows macierzy A: ";
    std::cin >> rows;

    // sprawdzanie czy `rows` jest dodatnie
    if (rows <= 0) {
        std::cout << "Wartość nie jest dodatnia!";
        return 0;
    }

    // wprowadzanie liczby kolumn macierzy `A`
    std::cout << "Wprowadź liczbę kolumn m macierzy A: ";
    std::cin >> cols;

    // sprawdzanie czy `m` jest dodatnie
    if (cols <= 0) {
        std::cout << "Wartość nie jest dodatnia!";
        return 0;
    }

    int **A = new int*[rows];
    // wypełnianie macierzy `A`
    int decyzja = -1;

    // blok podejmujący decyzję na podstawie `decyzja`
    while (decyzja != 0 && decyzja != 1) {
        std::cout
                << "Jeżeli chcesz samodzielnie wprowadzić elementy macierzy wprowadź `0` w przeciwnym wypadku wprowadź `1` by zostały wprowadzone w sposób losowy: ";
        std::cin >> decyzja;
        if (decyzja == 0) {

            // petla do wypełniania tablicy przez użytkownika
            for (int i = 0; i < rows; ++i) {
                A[i] = new int[cols];
                for (int j = 0; j < cols; ++j) {
                    std::cout << "Wprowadź wartośc elementu tablicy o indeksie " << i << "," << j << " : ";
                    std::cin >> A[i][j];
                }
            }
        } else if (decyzja == 1) {

            // pętla wypełniająca tablicę losowymi liczbami
            for (int i = 0; i < rows; i++) {
                A[i] = new int[cols];
                std::cout << "[ ";
                for (int j = 0; j < cols; j++) {
                    // A[i] = rand() % RAND_MAX; dla bardzo losowych liczb
                    A[i][j] = rand() % 31;
                    std::cout << std::setw(3) << A[i][j];
                    if (j + 1 < cols) {
                        std::cout << ", ";
                    }
                }
                std::cout << " ]" << std::endl;
            }

        }
    }
    return A;
}

void print_matrix(int** matrix,int m,int n){
    std::cout << std::endl;
    for (int i = 0; i < m; i++) {
        std::cout << "[ ";
        for (int j = 0; j < n; j++) {
            std::cout << std::setw(3) << matrix[i][j];
            if (j + 1 < n) {
                std::cout << ", ";
            }
        }
        std::cout << " ]" << std::endl;
    }
}

int **merge(int **A, int m, int n, int **B, int k, int l) {
    if(m!=k || n!=l) return (int**)null_msg("Macierze nie są tego samego wymiaru!");

    // `A` + `B` = `C`
    int **C = new int*[m];
    for (int i = 0; i < m; i++) {
        C[i] = new int[n];
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j]+B[i][j];
        }
    }
    return C;
}

int *sum_diagonal(int **A, int m, int n){
    int *sum = new int;
    if(m!=n) return null_msg("Macierz nie jest kwadratowa!");

    for (int i = 0; i < m; ++i) {
        *sum+=A[i][i];
    }
    return sum;
}

int *min_above_diagonal(int **A, int m, int n){
    if(m!=n) return null_msg("Macierz nie jest kwadratowa!");
    int *pointer = new int[2];
    int i_min=0,j_min=1;
    for (int i = 0; i < m-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            if(A[i_min][j_min] > A[i][j]){
                i_min = i;
                j_min = j;
            }
        }
    }
    pointer[0] = i_min;
    pointer[1] = j_min;

    return pointer;
}

int *into_array(int **A, int m, int n){
    int *C = new int[m*n];
//    for (int i = 0; i < m; ++i) {
//        for (int j = 0; j < n; ++j) {
//            C[n*i+j] = A[i][j];
//        }
//    }
    for (int i = 0; i < m*n; ++i) {
    C[i] = A[i/m][i%m];
    }
    return C;
}

int **transformZ90Left(int **A, int m, int n){
    int **C = new int*[n];
    for (int i = 0; i < n; ++i) {
        C[i] = new int[m];
        for (int j = 0; j < m; ++j) {
            C[i][j] = A[j][n-i-1];
        }
    }
    return C;
}

int **transformZ90Right(int **A, int m, int n){
    int **C = new int*[n];
    for (int i = 0; i < n; ++i) {
        C[i] = new int[m];
        for (int j = 0; j < m; ++j) {
            C[i][j] = A[m-j-1][i];
        }
    }
    return C;
}

int **transformY(int **A, int m, int n){
    int **C = new int*[m];
    for (int i = 0; i < m; ++i) {
        C[i] = new int[n];
        for (int j = n-1; j >=0; j--) {
            C[i][n-j-1] = A[i][j];
        }
    }
    return C;
}

int **transformX(int **A, int m, int n){
    int **C = new int*[m];
    for (int i = 0; i <m; i++) {
        C[i] = new int[n];
        for (int j = 0; j < n; j++) {
            C[i][j] = A[m-i-1][j];
        }
    }
    return C;
}

int **transpose(int **A, int m, int n){
    int **C = new int*[n];
    for (int i = 0; i < n; ++i) {
        C[i] = new int[m];
        for (int j = 0; j < m; ++j) {
            C[i][j] = A[j][i];
        }
    }
    return C;
}

int **multiply_matrixes(int **A, int m, int n, int **B, int k, int l){
    if(n!=k) return (int**)null_msg("Macierze nie mogą być wymnożone!");
    int **C = new int*[m];
    for (int i = 0; i < m; ++i) {
        C[i] = new int[l];
        for (int j = 0; j < l; ++j) {
            int sum = 0;
            for (int g = 0; g < n; ++g) {
                sum+=A[i][g]*B[g][j];
            }
            C[i][j] = sum;
        }
    }
    return C;
}

int **rotate90left_in_situ_quad(int **A, int n){
    int temp;
    for (int i = 0; i < n / 2; ++i) {
        for (int j = i; j < n - i -1; ++j) {
            temp = A[i][j];
            //z prawej na górę
            A[i][j] = A[j][n-i-1];
            // z dołu na prawo
            A[j][n-1-i] = A[n-1-i][n-1-j];
            // z lewej na dół
            A[n-1-i][n-1-j] = A[n-1-j][i];
            // do lewej
            A[n-1-j][i] = temp;
        }
    }
    return A;
}

int **rotate90left_in_situ_slower(int **A, int m, int n){
    int temp;
    for (int i = 0; i < m; i++) {
        for (int j = i; j < n; j++) {
            temp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = temp;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0, k = n - 1; j < k; j++, k--) {
            temp = A[j][i];
            A[j][i] = A[k][i];
            A[k][i] = temp;
        }
    }
    return A;
}


