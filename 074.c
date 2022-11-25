#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Result {
    double res;
    int iter;
};

double error = 1e-6;
double h = 1e-4;

double f(double x) {
    return x + 1.0/2.0 - sqrt(1.0 - x*x);
}

double g(double x) {
    return x + 1.0/2.0 + sqrt(1.0 - x*x);
}

double newton(double (*func)(double), double init, int max_iter, int *iter) {
    double x = init;
    double x_n;

    for (int i = 0; i < max_iter; i++) {
        *iter = i;
        if (isnan(x)) {
            break;
        }
        double df = (func(x + h) - func(x)) / h; // derivative
        x_n = x - func(x) / df;
        if (fabs(x_n - x) < error) {
            return x_n;
        }
        x = x_n;
    }

    return strtod("nan", NULL);
}

double bisection(double (*func)(double), double a, double b, int max_iter, int *iter) {
    double c;

    for (int i = 0; i < max_iter; i++) {
        *iter = i + 1;
        c = (a + b) / 2.0;
        if (fabs(a - c) < 2 * error) {
            return c;
        } else {
            if (func(c) > 0) {
                b = c;
            } else if (func(c) < 0) {
                a = c;
            } else {
                return c;
            }
        }
    }

    return strtod("nan", NULL);
}

void print_result(double ans, int iter) {
    if (isnan(ans)) {
        printf("not converged\n");
    } else {
        printf("(%d times): (%+.6f, %+.6f)\n", iter, ans, ans + 0.5);
    }
}

int main(void) {
    double x_0 = 0.0; // init value
    double x_1 = 0.0; // init value
    int i;

    double newton_ans_0 = newton(f, x_0, 20, &i);
    int newton_iter_0 = i;
    double newton_ans_1 = newton(g, x_1, 20, &i);
    int newton_iter_1 = i;

    double bisec_ans_0 = bisection(f, -1.0, 1.0, 20, &i);
    int bisec_iter_0 = i;
    double bisec_ans_1 = bisection(g, -1.0, 1.0, 20, &i);
    int bisec_iter_1 = i;

    printf("Newton-Raphson method:\n");
    printf("Upper part: ");
    print_result(newton_ans_0, newton_iter_0);
    // イテレーションの1回目で x_n = -1.5 となり、f(x) の定義域から外れて nan となる -> not converged
    printf("Lower part: ");
    print_result(newton_ans_1, newton_iter_1);

    printf("Bisection method:\n");
    printf("Upper part: ");
    print_result(bisec_ans_0, bisec_iter_0);
    printf("Lower part: ");
    print_result(bisec_ans_1, bisec_iter_1);

    return 0;
}
