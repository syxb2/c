#include <stdio.h>

int main() {
  char arr[128] = { '\0' };
  char *p = arr;
  char a;

  while ((a = getchar()) != '\n') {
    *p = a;
    ++p;
  }

  int i = 127;
  do {
    printf("%c", arr[i]);
    --i;
  } while (i != 0);
  printf("%c\n", arr[0]);

  return 0;
}