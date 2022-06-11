#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int n;
  double x;

  printf("x = ");
  scanf("%lf", &x);
  printf("%f -> ", x);
  n = x ? printf("True\n") : printf("False\n");
  printf("printed characters = %d\n", n);

  return 0;
}

/*
(base) keter@keternoAir univ % ./ex14
x = 123
123.000000 -> True
printed characters = 5
(base) keter@keternoAir univ % ./ex14
x = 0
0.000000 -> False
printed characters = 6
(base) keter@keternoAir univ % 
*/