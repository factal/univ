#include <stdlib.h>
#include <stdio.h>

void PrintCoeffMat(int n, double mat[n][n], double vec[n][1]) {
    printf("(A, b) =\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3.2f\t", mat[i][j]);
        }
        printf("| %3.2f", vec[i][0]);
        printf("\n");
    }
}

void GaussElimination(int n, double a[n][n], double b[n][1]) {
    PrintCoeffMat(n, a, b);
    // forward elimination
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double ratio = a[j][i] / a[i][i];
            for (int k = i; k < n; k++) {
                a[j][k] -= ratio * a[i][k];
            }
            b[j][0] -= ratio * b[i][0];
        }
        PrintCoeffMat(n, a, b);
    }

    // back substitution
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            b[i][0] -= a[i][j] * b[j][0];
        }
        b[i][0] /= a[i][i];
        PrintCoeffMat(n, a, b);
    }
}


int main() {
    // input dimension
    int n;
    printf("n = ");
    scanf("%d", &n);

    // input matrix A and vector b
    double a[n][n], b[n][1];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%lf", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        printf("b[%d] = ", i);
        scanf("%lf", &b[i][0]);
    }

    // execute Gauss elimination
    GaussElimination(n, a, b);

    return 0;
}


