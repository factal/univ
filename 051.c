#include <stdlib.h>
#include <stdio.h>

void main() {
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
}