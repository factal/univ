#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define deg2rad(deg)  ((deg)*M_PI/180)
#define rad2deg(rad)  ((rad)*180/M_PI)

typedef struct {
  double x, y, z;
} Vec3;
typedef struct {
  double r, t, p;
} Pol3;

Vec3 vadd(Vec3 a, Vec3 b)
{
  Vec3 v;
  v.x = a.x + b.x;
  v.y = a.y + b.y;
  v.z = a.z + b.z;
  return (v);
}

Vec3 vsub(Vec3 a, Vec3 b)
{
  Vec3 v;
  v.x = a.x - b.x;
  v.y = a.y - b.y;
  v.z = a.z - b.z;
  return (v);
}

double viprod(Vec3 a, Vec3 b)
{
  return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vec3 voprod(Vec3 a, Vec3 b)
{
  Vec3 c;
  c.x = a.y * b.z - a.z * b.y;
  c.y = a.z * b.x - a.x * b.z;
  c.z = a.x * b.y - a.y * b.x;
  return (c);
}

double vabs(Vec3 a)
{
  return sqrt(viprod(a, a));
}

double varg(Vec3 a, Vec3 b)
{
  return acos(viprod(a, b) / (vabs(a) * vabs(b)));
}

Vec3 pol3tovec3(Pol3 pv)
{
  Vec3 v;
  v.x = pv.r * sin(pv.t) * cos(pv.p);
  v.y = pv.r * sin(pv.t) * sin(pv.p);
  v.z = pv.r * cos(pv.t);
  return (v);
}
