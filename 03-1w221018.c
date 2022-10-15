#include <stdlib.h>
#include <stdio.h>



// *mat: a pointer of matrix
// n: dim of matrix 
void PrintMatrix(double **mat, int col, int row) {
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            printf("%f\t", mat[col][row]);
        }
        printf("\n");
    }
}

// *mat: a pointer of matrix
// n: dim of matrix
double DotMatrix(double mat[3][3], double *vec, double *buffer, int n) {
    double *ai; // pointer of row
    ai = mat[0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            buffer[i] += *ai * vec[j];
            ai++;
        }
    }
}


int main() {
    /*
    double **a, *x;
    int n ;

    a = (double **) malloc(n * sizeof(double*)); // matrix
    for (int i = 0; i < n; i++) {
        a[i] = (double *) malloc(n * sizeof(double));
    }
    x = (double *) malloc(n * sizeof(double)); // vector

    if (a == NULL || x == NULL) {
        printf("Error: memory not allocated");
        exit(1);
    }
    */

    double a[3][3] = {
        {2, 4, 6},
        {3, 8, 7},
        {5, 7, 21}
    };

    double x[3] = {-33, 9, 6};

    int n = 3;

    double y[3];

    DotMatrix(a, x, y, n);

    // PrintMatrix(a, n, n);

    return 0;
}