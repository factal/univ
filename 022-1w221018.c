#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void PrintVector(double *v) {
    for (int i=0; i<3; i++) {
        printf("%6.1f\n", v[i]);
    }
}


int main(void) {
    double a[3][3] = {
        { -11.0,  -7.0, -10.0 },
        {  -5.0,  -3.0,  -5.0 },
        { -11.0,  -7.0, -10.0 }
    };

    double x[3] = { -3.0, 3.0, 1.0 };

    double y[3] = { 0.0, 0.0, 0.0 };

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            y[i] += a[i][j] * x[j];
        }
    }

    printf("A=\n");

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            printf("%6.1f", a[i][j]);
            if (j >= 2) {
                printf("\n");
            }
        }
    }

    printf("x=\n");
    PrintVector(x);

    printf("y=\n");
    PrintVector(y);

    return 0;
}