#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double integ(/* complete it */, double x1, double x2, int n)
{
  int i;
  double dx = (x2 - x1)/n, s = 0.0;

  for (i = 0; i < n; i++) s += /* complete it */

  return s;
}

int main(int argc, char **argv)
{
  double xi, a = 0, b = M_PI/2;
 
  xi = integ(cos, a, b, 10000);
  printf("integration %s([%f, %f]) = %.15f\n", "cos", a, b, xi);
  printf("strict value = %.15f\n", sin(b) - sin(a));

  return 0;
}
