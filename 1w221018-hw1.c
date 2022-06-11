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

    if (d < 0) {
        x1 = (-b + sqrt(-d) * I) / 2;
        x2 = (-b - sqrt(-d) * I) / 2;
        printf("x1 = %e %ei \n", creal(x1), cimag(x1));
        printf("x2 = %e %ei \n", creal(x2), cimag(x2));
    } else if (d == 0) {
        x1 = -b / 2;
        printf("x1 = %e\n", creal(x1));
        printf("x2 = %e\n", creal(x1));
    } else {
        x1 = (-b + sqrt(d)) / 2;
        x2 = (-b - sqrt(d)) / 2;
        printf("x1 = %e\n", creal(x1));
        printf("x2 = %e\n", creal(x2));
    }

    return 0;
}

/*
note: K = 0.018

(base) keter@keternoMacBook-Air univ % gcc 1w221018-hw1.c -o hw1 -
Wall -lm
(base) keter@keternoMacBook-Air univ % ./hw1
Input coefficients with using comma:
b, c = 1, 0.018
x1 = -1.833622e-02
x2 = -9.816638e-01
(base) keter@keternoMacBook-Air univ % ./hw1
Input coefficients with using comma:
b, c = 0.018, 1
x1 = -9.000000e-03 9.999595e-01i 
x2 = -9.000000e-03 -9.999595e-01i 

*/