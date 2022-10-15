#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    printf("input a, b, and n (e.g. 3.14, 6.28, 10): ");
    double a, b;
    int n;
    scanf("%lf, %lf, %d", &a, &b, &n);

    double w = (b-a)/n;
    double area = 0.0;
    for (int i=0; i<n; i++) {
        double s = w * sin(a + w*i);
        area += s;
    }

    printf("integral of sin(x) on [%.2f, %.2f] = %.2f\n", a, b, area);

    return 0;
}