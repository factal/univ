#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    double a;
    printf("input angle [deg]: ");
    scanf("%lf", &a);

    double rad = a / 180.0 * M_PI;

    printf("%f [deg] = %f [rad]", a, rad);

    return 0;
}