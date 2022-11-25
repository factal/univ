#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double h = 1e-6;
double error = 1e-6;

double f(double x) {
    return x + 1.0/2.0 - sqrt(1.0 - x*x);
}

double g(double x) {
    return x + 1.0/2.0 + sqrt(1.0 - x*x);
}

double newton(double (*f)(double), double init, int max_iter) {
    double x = init;
    double x_n;

    for (int i = 0; i < max_iter; i++) {
        double df = (f(x + h) - f(x)) / h;
        x_n = x - f(x) / df;
        if (fabs(x_n - x) < error) {
            return x_n;
        }
        x = x_n;
    }

    return strtod("nan", NULL);
}

int main(void) {
    double x_0 = 0.0; // init value
    double x_1 = -1.0; // init value

    double ans_0 = newton(f, x_0, 20);
    double ans_1 = newton(g, x_1, 20);

    printf("initial value: %.1f\n", x_0);

    if (isnan(ans_0)) {
        printf("not converged\n");
    } else {
        printf("answer_0 = %+.6f\n", ans_0);
    }

    printf("initial value: %.1f\n", x_1);
    if (isnan(ans_1)) {
        printf("not converged\n");
    } else {
        printf("answer_1 = %+.6f\n", ans_1);
    }

    return 0;
}
