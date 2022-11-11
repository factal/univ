#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void swap(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}

void print_coeff_mat(int n, double mat[n][n], double vec[n]) {
    printf("(A | b) =\n");
    for (int i = 0; i < n; i++) {
        printf("\t");
        for (int j = 0; j < n; j++) {
            printf("%2.1f\t", mat[i][j]);
        }
        printf("| %2.1f\n", vec[i]);
    }
}

int find_max_col_index(int n, int start, double mat[n][n]) {
    int max_index = start;
    double max = fabs(mat[start][start]);
    for (int i = start; i < n; i++) {
        if (fabs(mat[i][start]) > max) {
            max = fabs(mat[i][start]);
            max_index = i;
        }
    }
    return max_index;
}

void gauss_elim_with_pivot(int n, double mat[n][n], double vec[n]) {
    print_coeff_mat(n, mat, vec);
    // forward elimination
    for (int i = 0; i < n - 1; i++) {
        int max_index = find_max_col_index(n, i, mat);

        printf("colmun %d: row %d is max\n\n", i, max_index);

        // swap row i and row max_index
        if (max_index != i) {
            for (int j = 0; j < n; j++) {
                swap(&mat[i][j], &mat[max_index][j]);
            }
            swap(&vec[i], &vec[max_index]);
        }

        for (int j = i + 1; j < n; j++) {
            double ratio = mat[j][i] / mat[i][i];
            for (int k = i; k < n; k++) {
                mat[j][k] -= ratio * mat[i][k];
            }
            vec[j] -= ratio * vec[i];
        }
        print_coeff_mat(n, mat, vec);
        printf("\n");
    }

    // back substitution
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            vec[i] -= mat[i][j] * vec[j];
        }
        vec[i] /= mat[i][i];
        print_coeff_mat(n, mat, vec);
        printf("\n");
    }
}

int main() {
    // inputs
    int n;
    printf("n = ");
    scanf("%d", &n);

    double a[n][n], b[n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%lf", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        printf("b[%d] = ", i);
        scanf("%lf", &b[i]);
    }
    printf("\n");

    gauss_elim_with_pivot(n, a, b);

    return 0;
}
