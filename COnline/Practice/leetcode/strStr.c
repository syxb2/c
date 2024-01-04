#include <stdio.h>

/*
int strStr(char* haystack, char* needle) {
  char *temp = needle;
  int n = 0;
  while (*haystack != '\0' && *needle != '\0') {
    while (*needle != *haystack) {
      ++haystack;
      ++n;
      if (*haystack == '\0' && *needle != '\0') {
        break;
      }
    }
    int a = 0;
    while (*needle == *haystack && *haystack != '\0') {
      ++haystack;
      ++needle;
      ++a;
    }
    if (*haystack == '\0' && *needle != '\0') {
      break;
    }
    if (*needle == '\0') {
      return n;
    }
    else {
      needle = temp;
      n += a;
    }
  }
  return -1;
}
*/

int strStr(char* haystack, char* needle) {
  char *tneedle = needle;
  char *thaystack = haystack;
  int n = 0;
  while (*haystack != '\0') {
    if (*haystack == *needle) {
      while (*haystack == *needle && *needle != '\0') {
        ++haystack;
        ++needle;
        if (*haystack == '\0' && *needle != '\0') break;
      }
      if (*needle == '\0') {
        return n;
      }
      else {
        needle = tneedle;
      }
    }
    thaystack += 1;
    haystack = thaystack;
    ++n;
  }
  return -1;
}

int main() {
  char *h = "mississippi";
  char *n = "issip";
  // strstr(h, n);
  printf("%d\n", strStr(h, n));
  // printf("%c\n", a[1]);

  return 0;
}

