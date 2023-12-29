#include <stdio.h>

long fact(long n) {
  if (n == 1) {
    return 1;
  }
  return n * fact(n - 1);
}

int main() {
  long n;

  scanf("%ld", &n);
  n = fact(n);
  printf("%ld\n", n);

  return 0;
}