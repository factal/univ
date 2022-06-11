#include <complex.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {
    double b, c;
    double _Complex x1, x2;

    printf("Input coefficients with using comma:\n");

    printf("b, c = ");
    scanf("%lf,%lf", &b, &c);

    double d = b * b - 4 * c;
    double sqrtD = d >= 0 ? sqrt(d): sqrt(-d);
    double ans = b >= 0 ? -b / 2 - sqrtD / 2: -b / 2 + sqrtD / 2;

    if (d < 0) {
        x1 = ans * I;
        x2 = c / ans * I;
        printf("x1 = %.15e %.15ei \n", creal(x1), cimag(x1));
        printf("x2 = %.15e %.15ei \n", creal(x2), cimag(x2));
    }
    else {
        x1 = ans;
        x2 = c / ans;
        printf("x1 = %.15e\n", creal(x1));
        printf("x2 = %.15e\n", creal(x2));
    }

    return 0;
}

/*
(base) keter@keternoMacBook-Air univ % ./1w221018-rep7                    
Input coefficients with using comma:
b, c = 1, 18e-15
x1 = -9.999999999999820e-01
x2 = -1.800000000000032e-14
*/