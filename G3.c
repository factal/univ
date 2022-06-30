double G3(double f(), double a, double b)
{
  double x[] = {-sqrt(0.6), 0, sqrt(0.6)}, 
         c[] = {5.0/9, 8.0/9, 5.0/9},  
	   u = (b-a)/2, v=(a+b)/2, s = 0;
  int i;

  for (i = 0; i < 3; i++) s += c[i]*f(u*x[i] + v)*u;

  return s;
}
