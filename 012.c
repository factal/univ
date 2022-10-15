#include <stdio.h>
#include <math.h>

int main(void) {
    printf("input angle [deg]: ");
    double a;
    scanf("%lf", &a);

    double rad = a / 180.0 * M_PI;

    printf("sin(%6.3f[deg]) = sin(%6.3f[rad]) = %6.3f\n", a, rad, sin(rad));
    printf("cos(%6.3f[deg]) = cos(%6.3f[rad]) = %6.3f\n", a, rad, cos(rad));
    printf("tan(%6.3f[deg]) = tan(%6.3f[rad]) = %6.3f\n", a, rad, tan(rad));

    return 0;
}