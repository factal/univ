#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func(double x) {
    return x - 1.2 * exp(-x);
}

double dfunc(double x) {
    return 1 + 1.2 * exp(-x);
}

double get_next_seq(double x) {
    return x - func(x) / dfunc(x);
}

int main(void) {
    double error = 1e-6;
    double x = 3.0; // init value
    double x_n;
    int i = 0;
    int max_iter = 100;

    printf("initial value: %.2f\n", x);
    
    while(i < max_iter) {
        x_n = get_next_seq(x);
        if (fabs(x_n - x) < error) {
            break;
        }
        x = x_n;
        printf("x(%03d) = %+.6f\n", i, x);

        i++;
    }

    if (i < max_iter) {
        printf("answer = %+.6f\n", x);
    } else {
        printf("not converged\n");
    }

    return 0;
}
