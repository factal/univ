#include <stdlib.h>
#include <stdio.h>

void DotMatAndVec(int n, double mat[n][n], double vec[n][1], double buffer[n][1]) {
    double *a_i = mat[0]; // pointer of row 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            buffer[i][0] += *a_i * vec[j][0];
            a_i++;
        }
    }
}

void PrintMat(int col, int row, double mat[col][row]) {
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            printf("%f\t", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("n = ");
    scanf("%d", &n);
    
    double a[n][n], x[n][1], y[n][1];

    // input of matrix a and vector x
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%lf", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%lf", &x[i][0]);
    }

    // dot product
    DotMatAndVec(3, a, x, y);

    // output
    printf("A = \n");
    PrintMat(n, n, a);
    printf("x = \n");
    PrintMat(n, 1, x);
    printf("y = \n");
    PrintMat(n, 1, y);

    return 0;
}