#include <stdio.h>

/*
char findTheDifference(char* s, char* t) {
  char* temp = s;
  while (*t != '\0') {
    while (*s != '\0') {
      if (*s != *t) {
        ++s;
      }
      else if (*s == *t) {
        s = temp;
        break;
      }
    }
    if (*s == '\0') {
      return *t;
    }
    else if (*s != '\0') {
      ++t;

    }
  }
  return 0;
}
*/

char findTheDifference(char* s, char* t) {
  int is = 0;
  int it = 0;
  for (; *s != '\0'; ++s) {
    is += *s;
  }
  for (; *t != '\0'; ++t) {
    it += *t;
  }
  char r = it - is;
  return r;
}

int main() {
  char *s = "asd";
  char *t = "dsac";

  printf("%c\n", findTheDifference(s, t));

  return 0;
}

