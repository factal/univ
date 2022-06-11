#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
    double r;

    printf("radius = ");
    scanf("%lf", &r);
    printf("area = %f\n", r * r * M_PI);
    return 0;
}