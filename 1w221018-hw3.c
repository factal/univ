#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vector.h"

Vec3 z = {0, 0, 1};

double Angle(Vec3 t[3]) {
    Vec3 a = vsub(t[1], t[0]);
    Vec3 b = vsub(t[2], t[0]);
    Vec3 normal = voprod(a, b);
    double angle = varg(normal, z);
    if (angle > M_PI / 2) {
        angle = M_PI - angle;
    }
    return angle;
}

int main() {
    int seed = 999;
    srand48(seed);
    double angle = 0;
    for (int i = 0; i < pow(10, 5); i++) {
        Vec3 tri[3];
        for (int j = 0; j < 3; j++) {
            tri[j].x = drand48();
            tri[j].y = drand48();
            tri[j].z = drand48();
        }
        angle += Angle(tri);
    }
    printf("Seed = %d\n", 18);
    printf("Average = %f\n", angle / pow(10, 5));
    return 0;
}
/*
(base) keter@keternoAir univ % gcc hw3.c -o hw3 -Wall
(base) keter@keternoAir univ % ./hw3                 
Seed = 18
Average = 0.998441
*/