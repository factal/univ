#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double integ(double (*f)(), double x1, double x2, int n)
{
  int i;
  double dx = (x2 - x1)/n, s = 0.0;

  for (i = 0; i < n; i++) s += f(x1 + (i + 0.5) * dx) * dx;

  return s;
}

double invexp(double x) {
  return exp(-x);
}

int main(int argc, char **argv) {
  double a = 0, b = 1.18;
  double strict = invexp(a) - invexp(b);

  printf("Integration of exp(-x) for [%f, %f] and errors\n", a, b);
  for (int i = 0; i < 7; i++) {
    int slices = pow(10, i);
    double ans = integ(invexp, a, b, slices);
    printf("%.15f, %e\n", ans, ans - strict);
  }
  printf("strict value = %.15f\n", strict);

  return 0;
}

/*
(base) keter@keternoMacBook-Air univ % ./hw2                          
Integration of exp(-x) for [0.000000, 1.180000] and errors
0.654106195986718, -3.861507e-02
0.692319530769592, -4.017306e-04
0.692717242477339, -4.018922e-06
0.692721221209494, -4.018937e-08
0.692721260996975, -4.018939e-10
0.692721261394864, -4.004685e-12
0.692721261398807, -6.172840e-14
strict value = 0.692721261398869
(base) keter@keternoMacBook-Air univ % 
*/