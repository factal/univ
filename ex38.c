#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x) {
  return x * 100.0;
}

int main(int argc, char **argv) {
  double x = 1, a[3] = { 10, 20, 30}, f();
  double *px, (*pa)[3], (*pf)();

  printf("&x = %p, *(&x) = %f\n", &x, *(&x));
  printf("&a = %p, *(&a) = %p\n", &a, *(&a));
  printf("&f = %p, *(&f) = %p\n", &f, *(&f));
  printf("a = %p, *a[0] = a[o] = %f\n", a, a[0]);

  px = &x;
  pa = &a;
  pf = &f;

  printf("px = %p, *px = %f\n", px, *px);
  printf("pa = %p, *pa = %p\n", pa, *pa);
  printf("pf = %p, *pf = %p\n", pf, *pf);
  printf("(*pf)(3.1) = %f\n", (*pf)(3.1));
  printf("(*pa)[0] = %f\n", (*pa)[1]);

  return 0;
}