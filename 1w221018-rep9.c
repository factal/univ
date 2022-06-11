#include <stdlib.h>
#include <stdio.h>

double max(double x, double y) {
    if (x >= y) return x;
    else return y;
};

int main() {
    double x, y;

    printf("x, y = ");
    scanf("%lf, %lf", &x, &y);
    printf("compare %g and %g ...\n", x, y);
    printf("%g is bigger\n", max(x, y));

    return 0;
};

/*
(base) keter@keternoAir univ % ./ex28                  
x, y = 2, 2.1
compare 2 and 2.1 ...
2.1 is bigger
(base) keter@keternoAir univ % ./ex28
x, y = -1.5, -7.98
compare -1.5 and -7.98 ...
-1.5 is bigger
(base) keter@keternoAir univ % 
*/