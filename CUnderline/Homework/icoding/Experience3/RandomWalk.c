#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void arr_initia (char *t) {
  char *p = t;
  for (int i = 0; i < 144; ++i, ++p) {
    *p = '.';
  }
  p = t;
  for (int i = 0; i < 12; ++i, ++p) {
    *p = '0';
  }
  p = t;
  for (int i = 0; i < 12; ++i, p += 12) {
    *p = '0';
  }
  p = t + 11;
  for (int i = 0; i < 12; ++i, p += 12) {
    *p = '0';
  }
  p = t + 12 * 11;
  for (int i = 0; i < 12; ++i, ++p) {
    *p = '0';
  }
}

// void print_arr (char *t) {
//   char *p = t;
//   for (int i = 0; i < 12; ++i) {
//     for (int i = 0; i < 12; ++i, ++p) {
//       printf("%c", *p);
//     }
//     printf("\n");
//   }
// }

void print_arr_2 (char *t) {
  char *p = t;
  for (int i = 0; i < 12; ++i) {
    for (int i = 0; i < 12; ++i, ++p) {
      if (*p != '0')
        printf("%c", *p);
    }
    printf("\n");
  }
}

int random_arr() {
  int a = rand();
  int b = 0;
  switch (a % 4) {
    case 0:
      b = 12;
      break;
    case 1:
      b = -12;
      break;
    case 2:
      b = 1;
      break;
    case 3:
      b = -1;
      break;
  }
  return b;
}

int main() {
  srand(time(NULL));
  char arr[12][12];
  arr_initia(arr);
  // print_arr(arr);
  char *p = arr;
  p += 13;
  int i = 0;
  int temp = 0;

  while (i < 26) {
    if (*p != '0' && *p == '.') {
      *p = 65 + i;
      temp = random_arr();
      if (*(p - 1) != '.' && *(p - 12) != '.' && *(p + 1) != '.' && *(p + 12) != '.')
        break;
      p = p + temp;
      ++i;
    }
    else {
      p = p - temp;
      temp = random_arr();
      if (*(p - 1) != '.' && *(p - 12) != '.' && *(p + 1) != '.' && *(p + 12) != '.')
        break;
      p = p + temp;
    }
  }

  // print_arr(arr);
  print_arr_2(arr);

  return 0;
}