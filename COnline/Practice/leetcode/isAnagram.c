#include <stdio.h>
#include <string.h>
#include<stdlib.h>


/*
char* arrangeInOrder(char *p) {
  static char arr[256];
  for (int i = 0; i < 256; ++i) {
    arr[i] = '\0';
  }
  for (int i = 0; *p != '\0'; ++p, ++i) {
    arr[i] = *p;
  }
  for (int i = 0; i < 256; ++i) {
    for (int j = 0; arr[j + 1] != '\0'; ++j) {
      if (arr[j] > arr[j + 1]) {
        char c = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = c;
      }
    }
  }
  return arr;
}

bool isAnagram(char* s, char* t) {
  char *a = arrangeInOrder(s);
  char arrs[256] = { '\0' };
  for (int i = 0; i < 256; ++i, ++a) {
    arrs[i] = *a;
  }
  char *b = arrangeInOrder(t);
  char arrt[256] = { '\0' };
  for (int i = 0; i < 256; ++i, ++b) {
    arrt[i] = *b;
  }
  int i;
  for (i = 0; (arrs[i] == arrt[i]) && arrs[i] != '\0' && arrt[i] != '\0'; ++i);
  if (arrs[i] == '\0' && arrt[i] == '\0') return 1;
  else return 0;
}
*/

int cmp(const void* _a, const void* _b) {
    char a = *(char*) _a, b = *(char*) _b;
    return a - b;
}

bool isAnagram(char* s, char* t) {
    int len_s = strlen(s), len_t = strlen(t);
    if (len_s != len_t) {
        return 0;
    }
    qsort(s, len_s, sizeof(char), cmp);
    qsort(t, len_t, sizeof(char), cmp);
    return strcmp(s, t) == 0;
}

int main() {
    char *s = "ab";
    char *t = "a";

    printf("%d\n", isAnagram(s, t));

    // printf("%s\n", arrangeInOrder(t));


    return 0;
}