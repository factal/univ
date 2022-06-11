#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  double x;

  printf("x = ");
  scanf("%lf", &x);
  printf("x = %g -> ", x);
  if (x) {
    printf("True\n");
  } else {
    printf("False\n");
  }
}

/*
(base) keter@keternoAir univ % ./ex11                           
x = 1  
x = 1 -> True
(base) keter@keternoAir univ % ./ex11
x = 0.00000
x = 0 -> False
(base) keter@keternoAir univ % ./ex11
x = 0.0000000001
x = 1e-10 -> True
*/