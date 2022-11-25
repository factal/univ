#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double h = 1e-4;

double func(double x) {
    return cos(x) - x * x;
}

double dfunc(double x) {
    return (func(x + h) - func(x - h)) / h;
}

double get_next_seq(double x) {
    return x - func(x) / dfunc(x);
}

int main(void) {
    double error = 1e-6;
    double x = 1.0; // init value
    double x_n;
    int i = 0;
    int max_iter = 20;

    printf("initial value: %.1f\n", x);
    
    while(i < max_iter) {
        x_n = get_next_seq(x);
        if (fabs(x_n - x) < error) {
            break;
        }
        x = x_n;
        i++;

        printf("x(%03d) = %+.6f\n", i, x);
    }

    if (i < max_iter) {
        printf("answer = %+.6f\n", x);
    } else {
        printf("not converged\n");
    }

    return 0;
}
