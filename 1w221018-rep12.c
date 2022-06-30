#include <stdio.h>
#include <math.h>

double G3(double f(), double a, double b, int n) {
  double x[] = {-sqrt(0.6), 0, sqrt(0.6)}, 
         c[] = {5.0/9, 8.0/9, 5.0/9},
         dab = (b - a) / n,
         ai,
         bi,
	       u   = dab / 2, 
         v,
         s   = 0,
         ss;

  for (; n >= 1; n--) {
    ai = dab * (n - 1) + a;
    bi = ai + dab;
    v = (ai + bi) / 2;
    ss = 0;
    
    for (int j = 0; j < 3; j++) ss += c[j] * f(u * x[j] + v) * u;

    s += ss;
  }

  return s;
}

double invexp(double x) {
  return exp(-x);
}

int main (int argc, char **argv) {
  double a = 0, b = 1.18;
  double strict = invexp(a) - invexp(b);

  printf("Integration of exp(-x) for [%f, %f] and errors\n", a, b);
  for (int i = 0; i < 4; i++) {
    int slices = pow(10, i);
    double ans = G3(invexp, a, b, slices);
    printf("%.15f, %+e\n", ans, ans - strict);
  }
  printf("strict value = %.15f\n", strict);

  return 0;
}