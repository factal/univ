#include <stdlib.h>
#include <stdio.h>

// *mat: a pointer of matrix
// n: dim of matrix 
void PrintMatrix(double **mat, int col, int row) {
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            printf("\t%f\t", mat[col][row]);
        }
        printf("\n");
    }
}

// *mat: a pointer of matrix
// n: dim of matrix
void DotMatAndVec(int n, double mat[n][n], double vec[3][1], double buffer[3][1]) {
    double *a_i = mat[0]; // pointer of row 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            buffer[i][0] += *a_i * vec[j][0];
            a_i++;
        }
    }
}


int main() {
    double **a, **x, **y;
    int n;

    printf("n = ");
    scanf("%d", &n);

    // // matrix
    a = (double **) malloc(n * sizeof(double*)); 
    for (int i = 0; i < n; i++) {
        a[i] = (double *) malloc(n * sizeof(double));
    }

    // // vector
    x = (double **) malloc(n * sizeof(double)); 
    y = (double **) malloc(n * sizeof(double));
    x[0] = (double *) malloc(sizeof(double));
    y[0] = (double *) malloc(sizeof(double));

    // check 
    if (a == NULL || x == NULL || y == NULL) {
        printf("Error: memory not allocated");
        exit(1);
    }

    int n_size = sizeof(n * n * sizeof(double)) / sizeof(double) / n;

    for (int i = 0; i < n_size; i++) {
        for (int j = 0; j < n; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%lf", &a[i][j]);
        }
    }

    for (int i = 0; i < n_size; i++) {
        scanf("x[0] = %lf", &x[i][0]);
    }

    // double a[3][3] = {
    //     {2, 4, 6},
    //     {3, 8, 7},
    //     {5, 7, 21}
    // };

    //double x[1][3] = {{ -33, 9, 6 }};

    // DotMatAndVec(n, a, x, y);

    printf("A = \n");
    PrintMatrix(a, n, n);
    // printf("x = \n");
    // PrintMatrix(1, n, x);
    // printf("y = \n");
    // PrintMatrix(1, n, y);

    return 0;
}