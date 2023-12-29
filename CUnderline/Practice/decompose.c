#include <stdio.h>
void decompose(double d, int* i, double* f) {
  *i = (int)d;
  *f = d - *i;
}
int main() {
  int i;
  double f, d;
  scanf("%lf", &d);
  decompose(d, &i, &f);
  printf("%d,%.3f\n", i, f);
  return 0;
}