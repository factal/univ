#include <stdio.h>
#include <stdlib.h>


typedef struct {
    double **items;
} Matrix;

// check the lengthes of a's colmun and b's row
void check_coresponding(Matrix a, Matrix b) {
    if (a[0].length == b.length) {
        ERROR("error: not corresponding");
        exit(1);
    }
}

// create (n: row, m: colmun)-matrix
Matrix new_mat(int n, int m) {
    Matrix mat;
    mat.items = (double**)malloc(sizeof(double*) * n);

    for (int i=0; i<n; i++) {
        mat.items[i] = (double*)malloc(sizeof(double) * m);
        if (mat.items[i] == NULL) {
            ERROR("error: malloc failed");
            exit(1);
        }
    }

    return mat;
}

Matrix to_mat(double **items) {
    Matrix mat;
    mat.items = items;
    return mat;
}

Matrix mat_prod(Matrix a, Matrix b) {
    check_coresponding(a, b);

    Matrix c = new_mat(a[0].length, b.length);

    for (int i=0; i<a[0].length; i++) {
        for (int j=0; j<b.length; j++) {
            c[i][j] = 0.0;
            for (int k=0; k<a.length; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return c;
}


int main(void) {
    double A[3][3] = {
        {3.0, 2.0, 5.0},
        {1.0, 4.0, 3.0},
        {0.0, 1.0, 6.0}
    };

    double x[3] = {-3.0, 2.0, -1.0};

    double ans[3] = {0.0, 0.0, 0.0};

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            ans[i] += A[i][j] * x[j];
        }
    }

    printf("y=\n");
    printf("%6.1f\n", ans[0]);
    printf("%6.1f\n", ans[1]);
    printf("%6.1f\n", ans[2]);

    return 0;
}