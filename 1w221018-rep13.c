#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "vector.h"

int main() {
  int i;
  double s1, s2, a, b, c, s;
  Vec3 v[3], va, vb, vc;
  srand(time(NULL));

  for (i = 0; i < 3; i++) {
    v[i].x = rand() % 10;
    v[i].y = rand() % 10;
    v[i].z = rand() % 10;
    
    printf("v[%d].x = %f, v[%d].y = %f, v[%d].z = %f\n", i, v[i].x, i, v[i].y, i, v[i].z);
  }

  va = vsub(v[1], v[0]);
  vb = vsub(v[2], v[1]);
  vc = vsub(v[0], v[2]);

  a = vabs(va);
  b = vabs(vb);
  c = vabs(vc);
  s = (a + b + c) / 2;

  s1 = vabs(voprod(va, vb)) / 2;
  s2 = sqrt(s * (s - a) * (s - b) * (s - c));
  printf("size1 = %f, size2 = %f\n", s1, s2);

  return 0;
}

/*
(base) keter@keternoAir univ % ./ex43 
v[0].x = 3.000000, v[0].y = 2.000000, v[0].z = 7.000000
v[1].x = 1.000000, v[1].y = 2.000000, v[1].z = 8.000000
v[2].x = 6.000000, v[2].y = 6.000000, v[2].z = 5.000000
size1 = 4.500000, size2 = 4.500000
*/