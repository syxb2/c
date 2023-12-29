#include <stdio.h>

long fibonacci(long n) {
  if (n <= 2) {
    return 1;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);
}

long fibonacci_2(long n, long a, long b) {
  if (n == 1) {
    return a;
  }
  return fibonacci_2(n - 1, b, a + b);
}

int main() {
  long n;

  scanf("%ld", &n);
  // printf("%ld\n", fibonacci(n));
  printf("%ld\n", fibonacci_2(n, 1, 1));

  return 0;
}