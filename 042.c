#include <stdio.h>
#include <stdlib.h>

void GaussElimination(int n, double mat[n][n], double vec[n][1], double buf[n][1]) {  
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double coeff = mat[j][i] / mat[i][i];
            printf("mat[%d][%d] ... %lf\n",i, j, coeff);
            for (int k = i; k < n - 1; k++) {
                mat[j][k] -= coeff * mat[i][i];
            }
            vec[j][0] -= coeff * mat[i][i];
        }
    }

    buf[n][0] = vec[n][0] / mat[n][n];
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            buf[i][0] = vec[i][0] - mat[i][j] * buf[j][0];
        }
        buf[i][0] /= mat[i][i];
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

    double a[n][n], b[n][1], buf[n][1]; // matrix, vector

    double c[3][3] = {{2, 4, 6}, {3, 8, 7}, {5, 7, 21}};
    double d[3][1] = {{6}, {15}, {24}};

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; i < n; j++) {
    //         printf("a[%d][%d] = ", i, j);
    //         scanf("%lf", &a[i][j]);
    //     }
    // }

    // for (int i = 0; i < n; i++) {
    //     printf("b[%d] = ", i);
    //     scanf("%lf", &b[i][0]);
    // }

    GaussElimination(n, c, d, buf);

    printf("c = \n");
    PrintMat(n, n, c);

    printf("buf = \n");

    PrintMat(n, 1, buf);

    return 0;
}